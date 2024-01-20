#include<stdio.h>
   #include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
	typedef struct node NODE;
	NODE *start=NULL,*p,*q;
	int ch,loc;
	void createatstart();
	void traverse();
	void createatend();
	void createatgivenlocation();
    void deleteatstart();
	void deleteatend();
    void deleteatgivenlocation();
	
int main()
{  
 do
    {
	printf("\n1.create at start\n2.traverse\n3.create at end\n5.create at given location\n5.delete at start\n6.delete at end\n7.delete at given location\n8.exit");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:createatstart(); 
			break;
			case 2:traverse(); 
			break;
			case 3: createatend();
			break;
			case 4:createatgivenlocation();
			break;
			case 5: deleteatstart();
			break;
			case 6: deleteatend();
			break;
			case 7: deleteatgivenlocation();
			break;
			case 8: 
			break;
			default:
				printf("invalid location");
			}
	}while(ch!=8);
	return 0;
}
void createatstart()
{
	p=(NODE*)malloc(sizeof(NODE));
 	    printf("enter data:");
	    scanf("%d",&p->data);
		if(start==NULL)
		{
		
			start=p;
			p->next=NULL;
			p->prev=NULL;
		}
		else
		{
			p->next=start;
			start->prev=p;
			p->prev=NULL;
			start=p;	
		}
}
void traverse()
{
		if(start==NULL)
		{
			printf("linked list is empty");
		}
		else
		{
			p=start;
			while(p!=NULL)
			{
				printf("\ndata element is %d",p->data);
				p=p->next;
			}
		}
}
void createatend()
{
	p=(NODE*)malloc(sizeof(NODE));
		printf("enter data:");
		scanf("%d",&p->data);
		if(start==NULL)
		{
			start=p;
			p->next=NULL;
			p->prev=NULL;
		}
		else
		{
			q=start;
			while(q->next!=NULL)
				{
					q=q->next;	
				}
			q->next=p;
			p->prev=q;
			p->next=NULL;
	    }
}
void createatgivenlocation()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter data:");
	scanf("%d",&p->data);
	printf("enter location :");
	scanf("%d",&loc);
		if(start==NULL)
			{   
		    	if(loc==1)
		    		{
						start=p;
						p->next=NULL;
						p->prev=NULL;
		    		}
		    	else
		    		{
		    			printf("invalid location");
					}
			}
		else
			{   
		    	if(loc==1)
		    		{   
		    			p->next=start;
		    			start=p;
		    			p->prev=NULL;
					}
				else
					{ 
						int i=1;
						q=start;
						while(i<loc-1 && q!=NULL)
							{
								q=q->next;
								i++;
		    				}
		    			if(q!=NULL)
		    				{ 
		    					p->next=q->next;
		       					if(q->next!=NULL)
		       						{
		        						q->next->prev=p;
			   						}
								p->prev=q;
								q->next=p;
		    				}
							else
								{
									printf("invalid location");
								}
		    		}
			}	
}

void deleteatstart()
{
	if(start==NULL)
		{
			printf("linked link empty.Delete is not possible");
		}
		else if (start->next==NULL)
		{
			p=start;
			start=NULL;
			printf("\n deleted data is %d",p->data);
			free(p);
		}
		else
		{
			p=start;
			start=start->next;
			start->prev=NULL;
			printf("\n deleted data is %d",p->data);
			free(p);
			
		}
}
void deleteatend()
{
	if(start==NULL)
		{
			printf("linked link empty .delete is not possible");
		}
		else if (start->next==NULL)
		{
			p=start;
			start=NULL;
			printf("\n deleted data is %d",p->data);
			free(p);
		}
		else
		{
			p=start;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			q=p->prev;
			q->next=NULL;
			printf("\n deleted data is %d",p->data);
			free(p);
		}
}
		    
void deleteatgivenlocation()
{
	printf("enter location :");
	scanf("%d",&loc);
	if(start==NULL)
		{
			printf("\nlinked link empty.Delete is not possible");
		}
		
	else
		{
			if(loc==1)
				{
					p=start;
					if(p->next==NULL)
						{
							start=NULL;
							printf("\n deleted data is %d",p->data);
			    			free(p);
						}
				    start=p->next;
		    		start->prev=NULL;
					printf("\n deleted data is %d",p->data);
					free(p);
				}
			else
				{
					int a=1;
					p=start;
					while(a<loc&&p!=NULL)
						{
						p=p->next;
						a++;
						}
					if(p!=NULL)
						{
							p->prev=q;
							if(p->next==NULL)
								{
									q->next=NULL;	
								}
							q->next=p->next;
						    printf("\n deleted data is %d",p->data);
							free(p);
						}
				}
			
		}
}