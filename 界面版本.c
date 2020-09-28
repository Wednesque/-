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
void add_subtract(struct polynomial *head1,struct polynomial *head2);//加减法
void multiplication(struct polynomial *head1,struct polynomial *head2);//相乘
void display(struct polynomial *head);//输出

int count;

void main()
{
	int choice,i;
	node *head1=NULL;
	node *head2=NULL;
	do{
		system("cls");
		printf("\n");
		printf("┏━━━━━一元稀疏多项式运算━━━━━┓\n");
		printf("┃                                      ┃\n");
		printf("┃1----创建多项式 A&B    2----加法 A+B  ┃\n");
		printf("┃                                      ┃\n");
		printf("┃3----减法 A-B          4----减法 B-A  ┃\n");
		printf("┃                                      ┃\n");
		printf("┃5----乘法 A*B          0----退出程序  ┃\n");
		printf("┃                                      ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━┛\n");
		printf(" 请输入您的选择：");
		scanf("%d",&choice);
		printf(" ━━━━━━━━━━━━━━━━━━━━\n");
		switch (choice)
		{
		case 0:break;
		case 1:
			{
				count=0;
				head1=create();
				head2=create();
				system("pause"); 
				break;
			}
		case 2:
			{
				if(head1==NULL){
					count=1;
					printf("A多项式不存在！\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B多项式不存在！");
					head2=create();
				}
				count=2;
				printf(" 多项式 A = ");
				display(head1);
				printf(" 多项式 B = ");
				display(head2);
				add_subtract(head1,head2); 
				system("pause"); 
				break;
			}
		case 3: 
			{
				if(head1==NULL){
					count=1;
					printf("A多项式不存在！\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B多项式不存在！");
					head2=create();
				}
				count=3;
				printf(" 多项式 A = ");
				display(head1);
				printf(" 多项式 B = ");
				display(head2);
				add_subtract(head1,head2); 
				system("pause"); 
				break;
			}
		case 4:
			{
				if(head1==NULL){
					count=1;
					printf("A多项式不存在！\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B多项式不存在！");
					head2=create();
				}
				count=4;
				printf(" 多项式 A = ");
				display(head1);
				printf(" 多项式 B = ");
				display(head2);
				add_subtract(head2,head1); 
				system("pause"); 
				break;
			}
		case 5: 
			{
				if(head1==NULL){
					count=1;
					printf("A多项式不存在！\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B多项式不存在！");
					head2=create();
				}
				count=5;
				printf(" 多项式 A = ");
				display(head1);
				printf(" 多项式 B = ");
				display(head2);
				multiplication(head1,head2); 
				system("pause"); 
				break;
			}
		}
	} while (choice);
}
struct polynomial *create()
{
	node *head=NULL,*p1,*p2=NULL;
	int n;//项数
	int i;
	count++;
	printf(" 请输入多项式");
	if(count==1)printf(" A ");
	else printf(" B ");
	printf("的 <项数>：");
	scanf("%d",&n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//动态创建链表
	for(i=1;i<=n;i++)
	{
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next =NULL;
		printf(" 请输入多项式");
		if(count==1)printf(" A ");
		else printf(" B ");
		printf("的第 %d 项系数和指数：",i);
		scanf("%lf",&p1->coefficient);
		scanf("%d",&p1->index );
		if(i==1)head->next =p1;//输入是第一项时，头节点指针指向第一项
		else p2->next = p1;//连接链表
		p2 = p1;
	}
	printf(" 多项式");
	if(count==1)printf(" A = ");
	else printf(" B = ");
	sort(head);
	display(head);
	printf(" ━━━━━━━━━━━━━━━━━━━━\n");
	return head;
}
void sort(struct polynomial *head)
{
	node *p1,*curr,*pre,*p2;//新建链表
	p1 = head->next  ;//p1指针所指向的结点要逐个取出作为插入结点
	head->next = NULL;//head指针带头结点，初始为空链表
	while(p1 != NULL)//p1指针不为空时循环
	{
		curr = head->next  ;
		pre = head ;
		//定位插入位置，退出循环时，pre指针向要插入节点的位置
		while(curr != NULL && curr->index >= p1->index )
		{
			pre = curr ;
			curr = curr->next ;
		}
		p2 = p1; //p2指针指向要插入结点的位置
		p1 = p1->next ;//p1指针指向下一个结点
		//p2指针所指结点插入pre指针所指结点后
		p2->next = pre->next ;
		pre->next = p2;
	}
}
void add_subtract(struct polynomial *head1,struct polynomial *head2)
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
		if(count==2)p1->coefficient=pp->coefficient;//加法直接复制
		if(count==3||count==4)p1->coefficient=(-1.0)*pp->coefficient;//减法取相反数
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
	if(count==2)printf(" A + B = ");
	if(count==3)printf(" A - B = ");
	if(count==4)printf(" B - A = ");
	sort(head);
	display(head);
	printf(" ━━━━━━━━━━━━━━━━━━━━\n");
}
void multiplication(struct polynomial *head1,struct polynomial *head2)
{
	node *head=NULL;//相乘后的多项式所有项的链表头节点
	node *p1=NULL;//中间变量
	node *p2=NULL;//保留前一个结点
	node *p=NULL;//第一个多项式的循环变量
	node *pp=NULL;//第二个多项式的循环变量
	if((head=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
		printf("ERROR");
		exit(0);
	}
	head->next=NULL;
	//两个循环建立多项式相乘后所有项的存储链表
	for(p=head1->next;p!=NULL;p=p->next){
		for(pp=head2->next; pp!=NULL ; pp=pp->next){
			if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
				printf("ERROR");
				exit(0);
			}
			p1->next=NULL;
			p1->coefficient=p->coefficient*pp->coefficient;//系数相乘
			p1->index=p->index+pp->index;//指数相加
			if(head->next==NULL)head->next=p1;//添加到新建链表
			else p2->next=p1;
			p2=p1;
		}
	}
	for(p=head->next;p!=NULL;p=p->next){//合并多项式，相同指数项合并
		for(pp=p->next,p2=p;pp!=NULL;pp=pp->next,p2=p2->next){
			if(p->index==pp->index){
				p->coefficient=p->coefficient+pp->coefficient;
				pp=pp->next;
				p2->next=pp;
			}
		}
	}
	if(count==5)printf(" A * B = ");
	sort(head);
	display(head);
	printf(" ━━━━━━━━━━━━━━━━━━━━\n");
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