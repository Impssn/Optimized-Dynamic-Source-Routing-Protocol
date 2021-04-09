#include<iostream>
using namespace std;
class conn                                             // class used to bind all func() together
{
    public:
	        static const int no_of_nodes=6;           // Here : no_of_nodes assumed to be 6
			int arcn[no_of_nodes][no_of_nodes],brcn[no_of_nodes][no_of_nodes],b1[no_of_nodes][no_of_nodes],b2[no_of_nodes][no_of_nodes];
	        int path[50];
	        int c,a=1,h=999,i,j,l,com=0;                      // initial initializations
			bool dir_link=0,out_of_range=0,req_dst_same=0;         // initial initializations
	        conn()
	        {
	        	for(i=0;i<no_of_nodes;i++)  
	        	{
	        		for(j=0;j<no_of_nodes;j++)
	        		{
	        			arcn[i][j]=0;
	        			brcn[i][j]=0;
	        			b1[i][j]=1000;       // Here : 1000 is assumed to be INFINITY
	        			b2[i][j]=1000;
					}
				}
				for(i=0;i<50;i++)
				   path[i]=0;
			}
		    void addnodecn(int src,int dst,int free,int wt) //getting the node connections
	        {
	        	brcn[src][dst]=brcn[dst][src]=1;
	        	b1[src][dst]=b1[dst][src]=wt;
	        	if(free==1)
	        	{
	        		arcn[src][dst]=arcn[dst][src]=1;
	        		b2[src][dst]=b2[dst][src]=wt;
				}
			}
			int balance(int c) // to get the next transmitted node of a packet
		    {
				l=0;
				for(j=0;j<no_of_nodes;j++)
				{
					if(b2[c][j]==h)
					{
						l=1;
						arcn[c][j]=arcn[j][c]=0;
						b2[c][j]=b2[j][c]=1000;
						c=j;
					}
					if(l==1)
					  return c;
					if(j==no_of_nodes-1)
					{
						if((a-2)<0)      //checks if source node lost from Network
						  return -1;
						c=path[a-2];
						a=a-2;
						return c;
					}
				}
			}
			void direct_link(int req,int dst)  // used if there exist a free link in-between req. and dst.
			{
				path[0]=req;
				path[1]=dst;
				dir_link=1;
			}
			void packetpath(int req,int dst)   // used to trace the path of a packet
			{	
			    if(req==dst)
			    {
			    	path[0]=req;
			    	path[1]=dst;
			    	req_dst_same=1;
			    	return;
				}
				if(req>(no_of_nodes-1)||dst>(no_of_nodes-1))
				{
					out_of_range = 1;
					return;
				}
				if(arcn[req][dst]==1)
				{
					direct_link(req,dst);
					return;
				}
				c=req;
				path[0]=c;
				goto transmit;
		        transmit: for(j=0;j<no_of_nodes;j++)   // transmit : used to do packet transmission
				          {
				            	if(b2[c][j]<h)
				     	          h=b2[c][j];
				     	        if(j==no_of_nodes-1)
				     	        {
				     		      c=balance(c);
				     		      if(c==-1)
				     		        return;
				     		      path[a]=c;
				       		      break;
						        }
					      }
			    if(path[a]==dst)
			       com=1;
			    if(com!=1)
			    {
			    	a=a+1;
			    	h=999;
			    	goto transmit;
				}
			}
	        void printpath()            // to print the packet's path as traced
		    { 
			    if(((a-2)<0&&dir_link!=1&&req_dst_same!=1)||(out_of_range==1))
			    {
			      cout<<"\n Necessary Node not in the Network";
			      return;
				}   
			   cout<<"\n The Packet is transmitted in path as: ";
			   for(int i=0;i<a+1;i++)
		       {
			    	cout<<path[i];
			  	    if(i<a)
			  	    cout<<"->";
		       }
		       refresh();
			}
			void printconn()      // used to print initial network and their respective link weights
			{
				cout<<"\n THE CONNECTION NETWORK:\n";
			   for(int i=0;i<no_of_nodes;i++)
			   {
			    	for(int j=0;j<no_of_nodes;j++)
				    {
					    cout<<"\t"<<brcn[i][j];
				    }
				    cout<<"\n";
			   }
			   cout<<"\n THE LINK WEIGHTS IN-BETWEEN THE NODES IN THE NETWORK:\n";
			   for(int i=0;i<no_of_nodes;i++)
			   {
			    	for(int j=0;j<no_of_nodes;j++)
				    {
					    cout<<"\t"<<b1[i][j];
				    }
				    cout<<"\n";
			   }
			}
			void refresh()  // used to refresh the network after all transmissions over
			{
				h=999;
				com=0;
				a=1;
				for(i=0;i<no_of_nodes;i++)
				{
					for(j=0;j<no_of_nodes;j++)
					{
						arcn[i][j]=brcn[i][j]=0;
						b1[i][j]=b2[i][j]=1000;
					}
				}
			}
};
int main()    
{
	conn obj;
	obj.addnodecn(0,2,1,5);  // addnodecn( src, dst, break-less-link, link-weight )
    obj.addnodecn(0,1,1,4);
    obj.addnodecn(2,3,1,1);
	obj.addnodecn(3,4,1,2);
	obj.addnodecn(3,5,1,6);
	obj.addnodecn(5,4,1,7);
	obj.addnodecn(3,1,1,3);
	obj.printconn();
	obj.packetpath(0,5);
	obj.printpath();  
}
