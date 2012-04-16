// lifted off the osm2pgsql source code.

#define _FILE_OFFSET_BITS 64
#define _LARGEFILE64_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <zlib.h>
#include <bzlib.h>

class BZ2Reader
 {
  char *name;

  void *fileHandle;
  // needed by bzip2 when decompressing from multiple streams. other
  // decompressors must ignore it.
  FILE *systemHandle; 
  int eof;
  char buf[4096];
  int buf_ptr, buf_fill;


// tries to re-open the bz stream at the next stream start.
// returns 0 on success, -1 on failure.
int bzReOpen(struct Input *ctx, int *error) {
  // for copying out the last unused part of the block which
  // has an EOS token in it. needed for re-initialising the
  // next stream.
  unsigned char unused[BZ_MAX_UNUSED];
  void *unused_tmp_ptr = NULL;
  int nUnused, i;

  BZ2_bzReadGetUnused(error, (BZFILE *)(ctx->fileHandle), &unused_tmp_ptr, &nUnused);
  if (*error != BZ_OK) return -1;
	      
  // when bzReadClose is called the unused buffer is deallocated, 
  // so it needs to be copied somewhere safe first.
  for (i = 0; i < nUnused; ++i)
    unused[i] = ((unsigned char *)unused_tmp_ptr)[i];
  
  BZ2_bzReadClose(error, (BZFILE *)(ctx->fileHandle));
  if (*error != BZ_OK) return -1;

  // reassign the file handle
  ctx->fileHandle = BZ2_bzReadOpen(error, ctx->systemHandle, 0, 0, unused, nUnused);
  if (ctx->fileHandle == NULL || *error != BZ_OK) return -1;

  return 0;
}

int readFile(void *context, char * buffer, int len)
{
    struct Input *ctx = context;
    void *f = ctx->fileHandle;
    int l = 0, error = 0;

    if (ctx->eof || (len == 0))
        return 0;
 
    l = BZ2_bzRead(&error, (BZFILE *)f, buffer, len);
    
    // error codes BZ_OK and BZ_STREAM_END are both "OK", but the stream 
    // end means the reader needs to be reset from the original handle.
    if (error != BZ_OK) {
      // for stream errors, try re-opening the stream before admitting defeat.
      if (error != BZ_STREAM_END || bzReOpen(ctx, &error) != 0) {
	l = 0;
	ctx->eof = 1;
      }
    }
    
    if (l < 0) {
      fprintf(stderr, "File reader received error %d (%d)\n", l, error);
        l = 0;
    }

    return l;
}

char inputGetChar(void *context)
{
    struct Input *ctx = context;

    if (ctx->buf_ptr == ctx->buf_fill) {
        ctx->buf_fill = readFile(context, &ctx->buf[0], sizeof(ctx->buf));
        ctx->buf_ptr = 0;
        if (ctx->buf_fill == 0)
            return 0;
        if (ctx->buf_fill < 0) {
            perror("Error while reading file");
            exit(1);
        }
    }
    //readFile(context, &c, 1);
    return ctx->buf[ctx->buf_ptr++];
}

int inputEof(void *context)
{
    return ((struct Input *)context)->eof;
}


void inputOpen(const char *name)
{
    const char *ext = strrchr(name, '.');
    struct Input *ctx = malloc (sizeof(*ctx));

    if (!ctx)
        return NULL;

    memset(ctx, 0, sizeof(*ctx));

    int error = 0;
    ctx->systemHandle = fopen(name, "rb");
    if (!ctx->systemHandle) {
      fprintf(stderr, "error while opening file %s\n", name);
      exit(10);
    }
    
    fileHandle = (void *)BZ2_bzReadOpen(&error, ctx->systemHandle, 0, 0, NULL, 0);

    
    if (!fileHandle) {
        fprintf(stderr, "error while opening file %s\n", name);
        exit(10);
    }
    buf_ptr = 0;
    buf_fill = 0;
    
}

int inputClose(void *context)
{
    struct Input *ctx = context;
    void *f = ctx->fileHandle;

    BZ2_bzclose((BZFILE *)f);

    return 0;
}

xmlTextReaderPtr inputUTF8(const char *name)
{
    void *ctx = inputOpen(name);

    if (!ctx) {
        fprintf(stderr, "Input reader create failed for: %s\n", name);
        return NULL;
    }

    return xmlReaderForIO(readFile, inputClose, (void *)ctx, NULL, NULL, 0);
}


int streamFile(char *filename) 
{
    xmlTextReaderPtr reader;
    int ret = 0;

    reader = inputUTF8(filename);

    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        while (ret == 1) {
            processNode(reader);
            ret = xmlTextReaderRead(reader);
        }

        if (ret != 0) {
            fprintf(stderr, "%s : failed to parse\n", filename);
            return ret;
        }

        xmlFreeTextReader(reader);
    } else {
        fprintf(stderr, "Unable to open %s\n", filename);
        return 1;
    }
    return 0;
}

};
