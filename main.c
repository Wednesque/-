#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial//多项式的每一项结构
{
	double coefficient;//系数
	int index;//指数
	struct polynomial *next;//指针
}node;

struct polynomial *create();//创建链表
void sort(struct polynomial *head);//排序
void add_subtract(struct polynomial *head1,struct polynomial *head2,int count);//加减法

void display(struct polynomial *head);//输出

void main()
{
    int n_1,n_2;
    int count;
	node *head1=NULL;
	node *head2=NULL;
    scanf("%d",&n_1);
    scanf("%d",&n_2);
    scanf("%d",&count);
	head1=create(n_1);
    head2=create(n_2);
    if(head1==NULL){
        head1=create();
    }
    if(head2==NULL){
        head2=create();
    }
    add_subtract(head1,head2,count);

}
struct polynomial *create(int n)
{
	node *head=NULL,*p1,*p2=NULL;
	//int n;//项数
	int i;
    //scanf("%d",&n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//动态创建链表
	for(i=1;i<=n;i++)
	{
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next =NULL;
		//printf(" 请输入多项式");
		//printf("的第 %d 项系数和指数：",i);
		scanf("%lf",&p1->coefficient);
		scanf("%d",&p1->index );
		if(i==1)head->next =p1;//输入是第一项时，头节点指针指向第一项
		else p2->next = p1;//连接链表
		p2 = p1;
	}

	return head;
}

void add_subtract(struct polynomial *head1,struct polynomial *head2,int count)
{
	node *head=NULL;//新建链表储存相加后多项式
	node *p1=NULL;//中间变量
	node *p2=NULL;//保留前一个结点
	node *p=NULL;//第一个多项式的循环变量
	node *pp=NULL;//第二个多项式的循环变量
	if((head=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
		printf("ERROR");
		exit(0);
	}
	head->next=NULL;
	for(pp=head2->next;pp!=NULL;pp=pp->next){//复制第二个多项式链表
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
			printf("ERROR");
			exit(0);
		}
		p1->next=NULL;
		if(count==0)p1->coefficient=pp->coefficient;//加法直接复制
		if(count==1)p1->coefficient=(-1.0)*pp->coefficient;//减法取相反数
		p1->index=pp->index;
		if(head->next==NULL)head->next=p1;
		else p2->next=p1;
		p2=p1;
	}
	for(p=head1->next;p!=NULL;p=p->next){//循环多项式的每一项
		for(pp=head->next,p2=head; pp!=NULL; ){
			if(p->index == pp->index){//指数相等
				pp->coefficient=p->coefficient+pp->coefficient;//系数相加
				if(pp->coefficient==0){
					pp=pp->next;
					p2->next=pp;
				}
				else{
					pp=pp->next;
					p2=p2->next;
				}
				break;
			}
			if(pp->next==NULL){//没有相同指数项，创建添加
				if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
					printf("ERROR");
					exit(0);
				}
				p1->next =NULL;
				p1->coefficient=p->coefficient;//多余项添加到新建链表
				p1->index=p->index;
				p1->next=head->next;
				head->next=p1;

				pp=pp->next;
				p2=p2->next;
				break;
			}
			pp=pp->next;
			p2=p2->next;
		}
	}
	//sort(head);
	//sort(head);
	display(head);
}

void display(struct polynomial *head)//输出函数
{
	struct polynomial *p=NULL;
	int i;
	for(p=head->next,i=0;p!=NULL;p=p->next,i++ )
	{
		if(p->index ==0){
			if(p->coefficient==0)break;
			else printf("%.2lf",p->coefficient );
		}
		else if(p->index==1){
			if(p->coefficient==1)printf("x");
			else if(p->coefficient==-1)printf("-x");
			else printf("%.2lfx",p->coefficient);
		}
		else if(p->index!=1){
			if(p->coefficient==1&&p->index>0)printf("x^%d",p->index);
			else if(p->coefficient==-1&&p->index>0)printf("-x^%d",p->index);
			else if(p->coefficient==1&&p->index<0)printf("x^(%d)",p->index);
			else if(p->coefficient==-1&&p->index<0)printf("-x^(%d)",p->index);
			else if(p->index<0)printf("%.2lfx^(%d)",p->coefficient,p->index);
			else printf("%.2lfx^%d",p->coefficient ,p->index );
		}
		if(p->next !=NULL&&p->next->coefficient >0)printf("+");
	}
	if(i==0)printf("0.00");
	printf("\n");
}
