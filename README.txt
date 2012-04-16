
Ideas :

      1. sorting of the data so that you can process a block of data at a time. 
      Make sure that all the nodes are in a certain order, even ways.(topological sorting)
      If we sort the world.osm file properly, and have an index, you should be able to just process a section of the 
      bz2 compressed file, extracting the needed block. If each block has an index of the nodes it contains, and each node belongs to a group or region in an intelligent way, then you will only be interested in a set of blocks and can just fetch a partial file. Of course between updates on the world file, the index will change, so you will need to consult an updated index. In general however, sorting the data will help alot. 

      2. If you want to create relations from ways, start with the points. 
      Each point that is part of the same set of ways gets put into a new way. 
      
      There has to be also no foreign nodes inside the way,at least not ones from interesting ways.
      We dont need to split the ways just because it has a shared point, only if the way of that point is interesting.

      For example, if we splitting common ways between admin borders, we want to only consider to split along common admin borders, not if a a street just shares a way. So for that we need to be able to preprocess the nodes. In the first step of the WaysToRelations.cpp processing,  the NodeProcessorShared.hpp . That first step is to look at the nodes  and index them by position. 
      to remove the duplicates (mark each node that has the same position to point to the first node).


      So the question is, is this other node reachable by all other (important) ways?

      How can we create groups? If we add the way ids together, will that create a unique id for all the nodes? Well we need to mark each node by the way that owns it. the first one, and the count of (important )ways that share it.

      
      3. Creating of chunks of data. What are the smallest rectangles that cover the area. If we take all the rectangles from the way bounding box and intersect them to create the smallest grid needed for an area. Each grid piece will be covered by one or may way bounding boxes. These grids can then be used to split up the points. Each grid can be said to be part of X other grids.

      How can we run an intersection of all the rectangles? We have to compare them all. 

Field Positions:
ID      3 
name    4  
count   5
MIN LAT 8
MIN LON 8


