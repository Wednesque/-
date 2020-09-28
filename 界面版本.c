#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial//����ʽ��ÿһ��ṹ
{
	double coefficient;//ϵ��
	int index;//ָ��
	struct polynomial *next;//ָ��
}node;

struct polynomial *create();//��������
void sort(struct polynomial *head);//����
void add_subtract(struct polynomial *head1,struct polynomial *head2);//�Ӽ���
void multiplication(struct polynomial *head1,struct polynomial *head2);//���
void display(struct polynomial *head);//���

int count;

void main()
{
	int choice,i;
	node *head1=NULL;
	node *head2=NULL;
	do{
		system("cls");
		printf("\n");
		printf("������������һԪϡ�����ʽ���㩥����������\n");
		printf("��                                      ��\n");
		printf("��1----��������ʽ A&B    2----�ӷ� A+B  ��\n");
		printf("��                                      ��\n");
		printf("��3----���� A-B          4----���� B-A  ��\n");
		printf("��                                      ��\n");
		printf("��5----�˷� A*B          0----�˳�����  ��\n");
		printf("��                                      ��\n");
		printf("������������������������������������������\n");
		printf(" ����������ѡ��");
		scanf("%d",&choice);
		printf(" ����������������������������������������\n");
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
					printf("A����ʽ�����ڣ�\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B����ʽ�����ڣ�");
					head2=create();
				}
				count=2;
				printf(" ����ʽ A = ");
				display(head1);
				printf(" ����ʽ B = ");
				display(head2);
				add_subtract(head1,head2); 
				system("pause"); 
				break;
			}
		case 3: 
			{
				if(head1==NULL){
					count=1;
					printf("A����ʽ�����ڣ�\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B����ʽ�����ڣ�");
					head2=create();
				}
				count=3;
				printf(" ����ʽ A = ");
				display(head1);
				printf(" ����ʽ B = ");
				display(head2);
				add_subtract(head1,head2); 
				system("pause"); 
				break;
			}
		case 4:
			{
				if(head1==NULL){
					count=1;
					printf("A����ʽ�����ڣ�\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B����ʽ�����ڣ�");
					head2=create();
				}
				count=4;
				printf(" ����ʽ A = ");
				display(head1);
				printf(" ����ʽ B = ");
				display(head2);
				add_subtract(head2,head1); 
				system("pause"); 
				break;
			}
		case 5: 
			{
				if(head1==NULL){
					count=1;
					printf("A����ʽ�����ڣ�\n");
					head1=create();
				}
				if(head2==NULL){
					count=2;
					printf("B����ʽ�����ڣ�");
					head2=create();
				}
				count=5;
				printf(" ����ʽ A = ");
				display(head1);
				printf(" ����ʽ B = ");
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
	int n;//����
	int i;
	count++;
	printf(" ���������ʽ");
	if(count==1)printf(" A ");
	else printf(" B ");
	printf("�� <����>��");
	scanf("%d",&n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//��̬��������
	for(i=1;i<=n;i++)
	{
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next =NULL;
		printf(" ���������ʽ");
		if(count==1)printf(" A ");
		else printf(" B ");
		printf("�ĵ� %d ��ϵ����ָ����",i);
		scanf("%lf",&p1->coefficient);
		scanf("%d",&p1->index );
		if(i==1)head->next =p1;//�����ǵ�һ��ʱ��ͷ�ڵ�ָ��ָ���һ��
		else p2->next = p1;//��������
		p2 = p1;
	}
	printf(" ����ʽ");
	if(count==1)printf(" A = ");
	else printf(" B = ");
	sort(head);
	display(head);
	printf(" ����������������������������������������\n");
	return head;
}
void sort(struct polynomial *head)
{
	node *p1,*curr,*pre,*p2;//�½�����
	p1 = head->next  ;//p1ָ����ָ��Ľ��Ҫ���ȡ����Ϊ������
	head->next = NULL;//headָ���ͷ��㣬��ʼΪ������
	while(p1 != NULL)//p1ָ�벻Ϊ��ʱѭ��
	{
		curr = head->next  ;
		pre = head ;
		//��λ����λ�ã��˳�ѭ��ʱ��preָ����Ҫ����ڵ��λ��
		while(curr != NULL && curr->index >= p1->index )
		{
			pre = curr ;
			curr = curr->next ;
		}
		p2 = p1; //p2ָ��ָ��Ҫ�������λ��
		p1 = p1->next ;//p1ָ��ָ����һ�����
		//p2ָ����ָ������preָ����ָ����
		p2->next = pre->next ;
		pre->next = p2;
	}
}
void add_subtract(struct polynomial *head1,struct polynomial *head2)
{
	node *head=NULL;//�½���������Ӻ����ʽ
	node *p1=NULL;//�м����
	node *p2=NULL;//����ǰһ�����
	node *p=NULL;//��һ������ʽ��ѭ������
	node *pp=NULL;//�ڶ�������ʽ��ѭ������
	if((head=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
		printf("ERROR");
		exit(0);
	}
	head->next=NULL;
	for(pp=head2->next;pp!=NULL;pp=pp->next){//���Ƶڶ�������ʽ����
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
			printf("ERROR");
			exit(0);
		}
		p1->next=NULL;
		if(count==2)p1->coefficient=pp->coefficient;//�ӷ�ֱ�Ӹ���
		if(count==3||count==4)p1->coefficient=(-1.0)*pp->coefficient;//����ȡ�෴��
		p1->index=pp->index;
		if(head->next==NULL)head->next=p1;
		else p2->next=p1;
		p2=p1;
	}
	for(p=head1->next;p!=NULL;p=p->next){//ѭ������ʽ��ÿһ��
		for(pp=head->next,p2=head; pp!=NULL; ){
			if(p->index == pp->index){//ָ�����
				pp->coefficient=p->coefficient+pp->coefficient;//ϵ�����
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
			if(pp->next==NULL){//û����ָͬ����������
				if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
					printf("ERROR");
					exit(0);
				}
				p1->next =NULL;
				p1->coefficient=p->coefficient;//��������ӵ��½�����
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
	printf(" ����������������������������������������\n");
}
void multiplication(struct polynomial *head1,struct polynomial *head2)
{
	node *head=NULL;//��˺�Ķ���ʽ�����������ͷ�ڵ�
	node *p1=NULL;//�м����
	node *p2=NULL;//����ǰһ�����
	node *p=NULL;//��һ������ʽ��ѭ������
	node *pp=NULL;//�ڶ�������ʽ��ѭ������
	if((head=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
		printf("ERROR");
		exit(0);
	}
	head->next=NULL;
	//����ѭ����������ʽ��˺�������Ĵ洢����
	for(p=head1->next;p!=NULL;p=p->next){
		for(pp=head2->next; pp!=NULL ; pp=pp->next){
			if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL){
				printf("ERROR");
				exit(0);
			}
			p1->next=NULL;
			p1->coefficient=p->coefficient*pp->coefficient;//ϵ�����
			p1->index=p->index+pp->index;//ָ�����
			if(head->next==NULL)head->next=p1;//��ӵ��½�����
			else p2->next=p1;
			p2=p1;
		}
	}
	for(p=head->next;p!=NULL;p=p->next){//�ϲ�����ʽ����ָͬ����ϲ�
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
	printf(" ����������������������������������������\n");
}
void display(struct polynomial *head)//�������
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