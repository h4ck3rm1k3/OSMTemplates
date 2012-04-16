
HEADERS= OSMAttributes.h \
	Point.hpp \
	BBox.hpp \
	Processor.hpp \
	OSMProcessor.hpp \
	World.hpp \
	SAX2OsmHandlers.hpp \
	NodeProcessor.hpp \
	WayProcessor.hpp \
	RelProcessor.hpp \
	NodeProcessorShared.hpp \
	WorldExtended.hpp \
	PointExtended.hpp

FindClosedWays : FindClosedWays.cpp $(HEADERS)
	#gcc -O0 -g FindClosedWays.cpp  -l xerces-c  -o FindClosedWays
	gcc -O4 -g FindClosedWays.cpp  -l xerces-c  -o FindClosedWays

WaysToRelations : WaysToRelations.cpp $(HEADERS) 
#	gcc -save-temps -pg -g WaysToRelations.cpp -I ../libsdbx/ -l xerces-c  -o WaysToRelations
	gcc -O4 WaysToRelations.cpp -I ../libsdbx/ -l xerces-c  -o WaysToRelations

TagReport : TagReport.cpp $(HEADERS)
#	gcc -pg -g TagReport.cpp -I ../libsdbx/ -l xerces-c  -o TagReport
	gcc -O4 TagReport.cpp  -l xerces-c  -o TagReport


IndexData : IndexWaysWithRTree.cpp $(HEADERS)
	gcc -O4 IndexWaysWithRTree.cpp -I ../libsdbx/ -l xerces-c  -o IndexWaysWithRTree

ExtractWays : ExtractWays.cpp $(HEADERS)
	gcc -O4 ExtractWays.cpp -l xerces-c  -o ExtractWays

ExtractCounties : ExtractCounties.cpp $(HEADERS)
	gcc -O4 ExtractCounties.cpp -l xerces-c  -o ExtractCounties


debug : ExtractWays.cpp $(HEADERS)
	gcc -pg -g ExtractWays.cpp -l xerces-c  -o ExtractWays

test: ExtractWays
	./ExtractWays new_jersey.osm

test_old: ExtractCounties
	./ExtractCounties lint.osm

clean:
	-	rm ExtractCounties
	rm ExtractWays