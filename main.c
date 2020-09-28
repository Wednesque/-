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
void add_subtract(struct polynomial *head1,struct polynomial *head2,int count);//�Ӽ���

void display(struct polynomial *head);//���

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
	//int n;//����
	int i;
    //scanf("%d",&n);
	head = (struct polynomial*)malloc(sizeof(struct polynomial));//��̬��������
	for(i=1;i<=n;i++)
	{
		if((p1=(struct polynomial*)malloc(sizeof(struct polynomial)))==NULL)
		{
			printf("ERROR");
			exit(0);
		}
		p1->next =NULL;
		//printf(" ���������ʽ");
		//printf("�ĵ� %d ��ϵ����ָ����",i);
		scanf("%lf",&p1->coefficient);
		scanf("%d",&p1->index );
		if(i==1)head->next =p1;//�����ǵ�һ��ʱ��ͷ�ڵ�ָ��ָ���һ��
		else p2->next = p1;//��������
		p2 = p1;
	}

	return head;
}

void add_subtract(struct polynomial *head1,struct polynomial *head2,int count)
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
		if(count==0)p1->coefficient=pp->coefficient;//�ӷ�ֱ�Ӹ���
		if(count==1)p1->coefficient=(-1.0)*pp->coefficient;//����ȡ�෴��
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
	//sort(head);
	//sort(head);
	display(head);
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
