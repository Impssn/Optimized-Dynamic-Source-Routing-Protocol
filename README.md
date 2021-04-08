# Optimized-Dynamic-Source-Routing-Protocol
This Algorithm does the _**Dynamic Source Routing in an Optimized way.**_
It also has the feature of _**self-healing**_ _**of link-breaks**_ by re-directing the packet 
through a proper route that connects the Destination.
  As per the Algorithm we first get the Source and Destination nodes and then find the Least distant node from Source.
  Then we forward the data packet to that node and we find the Least distant node from that node. We keep on doing this
  until we find the Destination node. Once we find the Destination node we pause there and return a Success message.
