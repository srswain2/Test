/**
*
* Nap$t3r : [SOUMYA.RANJAN.SWAIN]
*
**/

#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<set>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define for_loop(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define is_odd( num )   ((num) & 1)
#define is_even( num )  (!is_odd( (num) ))
#define TRACE
#define max(a,b) a>b?a:b
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define MAX (1+(1<<6))
#define MOD 1000000007
#define inf 0x7fffffff

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


inline int get_num()
{
	register int num=0;
	register char c;
	c=getchar();
	while(c>='0' && c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}


struct tree
{
	int data;
	tree* left;
	tree* right;
	tree* parent;
};

struct tree *newNode(int data)
{
	tree *node = (struct tree*)malloc ( sizeof ( struct tree ) ) ;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	
	return node;
}

struct tree *insertNode(struct tree *node, int data)
{
	static tree *par;
	tree *retnode;
	
	if(node == NULL)
	{
		retnode = newNode(data);
		retnode->parent = par;
		return retnode;
	}
	
	if(data <= node->data)
	{
		par = node;
		node->left = insertNode(node->left, data);
	}
	else
	{
		par = node;
		node->right = insertNode(node->right, data);
	}
	return node;
}

void inOrderTraversal(struct tree *root)
{
	if(root == NULL)
		return;
	inOrderTraversal(root->left);
	cout<<"Value: "<<root->data<<"\n";
	inOrderTraversal(root->right);
}

void preOrderTraversal(struct tree *root)
{
	if(root == NULL)
		return;
	cout<<"Value: "<<root->data<<"\n";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(struct tree *root)
{
	if(root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<"Value: "<<root->data<<"\n";
}

void clearLeafNodes(struct tree *node)
{
	if(node == NULL)
		return;
	if((node->left == NULL) && (node->right == NULL))
	{
		//delete node;
		cout<<"Value: "<<node->data<<"\n";
		struct tree *p;
		p = node->parent;
		if(node == p->left) 
			p->left = NULL;
		else
			p->right = NULL;
		free(node);
		
		return;
	}
	clearLeafNodes(node->left);
	clearLeafNodes(node->right);
}

int maxElementInTree(struct tree* root)
{
	int val, left_value, right_value, max = INT_MIN;
	if(root!=NULL)
	{
		val = root->data;
		left_value = maxElementInTree(root->left);
		right_value = maxElementInTree(root->right);
		
		if(left_value > right_value)
			max = left_value;
		else
			max = right_value;
		
		if(val > max)
			max = val;
	}
	return max;
}

int maxElementInTreeWithoutRecurssion(struct tree* root)
{
	int max = INT_MIN;
	queue<struct tree*> q;
	q.push(root);
	int i=0;
	while(!q.empty())
	{
		struct tree *temp1 = q.front();
		int temp = temp1->data;
		if(max<temp)
			max = temp;
		q.pop();
		
		if(temp1->left != NULL)
			q.push(temp1->left);
		if(temp1->right != NULL)
			q.push(temp1->right);
	}
	return max;
}

void deleteTree(struct tree* root)
{
	queue<struct tree*> q;
	if(root == NULL)
		cout<<"Empty\n";
	else
	{
		q.push(root);
		
		while(!q.empty())
		{
			struct tree* temp = q.front();
			q.pop();
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			if(temp->left == NULL && temp->right == NULL)
			{
				struct tree *p;
				p = temp->parent;
				if(temp == p->left) 
					p->left = NULL;
				else
					p->right = NULL;
				free(temp);
			}
		}
	}
}

bool findElement(struct tree* root, int element)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->data == element)
		{
			return 1;
		}
		else
		{
			int temp = findElement(root->left, element);
			if(temp == 1)
				return 1;
			else
				return findElement(root->right, element);
		}
	}
	return 0;
}

int treeSize(struct tree* node)
{
	if(node == NULL)
		return 0;
	else
		return (treeSize(node->left) + 1 + treeSize(node->right));
}

int identicalTrees(struct tree* node1, struct tree* node2)
{
	if(node1 == NULL && node2 == NULL)
		return 1;
	if(node1!= NULL && node2 != NULL)
	{
		return ((node1->data == node2->data) && (identicalTrees(node1->left, node2->left)) && (identicalTrees(node1->right, node2->right)));
	}
	else
	{
		return 0;
	}
}

int maxHeight(struct tree *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int max_left = maxHeight(root->left);
		int max_right = maxHeight(root->right);
		
		return max(max_left, max_right) + 1;
	}
}

void mirrorTree(struct tree *node)
{
	if(node == NULL)
		return;
	else
	{
		struct tree *temp;
		mirrorTree(node->left);
		mirrorTree(node->right);
		
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}


int main(int argc, char **argv)
{

	tree* root = newNode(6);   //inserting 0 as first element
	tree *root0 = newNode(6);
	
	insertNode(root, 3);
	insertNode(root, 5);
	insertNode(root, 1);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 8);
	insertNode(root, 7);
	insertNode(root, 9);
	insertNode(root, 10);
	
	insertNode(root0, 3);
	insertNode(root0, 5);
	insertNode(root0, 1);
	insertNode(root0, 2);
	insertNode(root0, 4);
	insertNode(root0, 8);
	insertNode(root0, 7);
	insertNode(root0, 9);
	insertNode(root0, 10);
	
	/*deleteTree(root);
	cout<<"DELETED\n";
	inOrderTraversal(root);  // In-Order Traversal of Tree*/
	
	if(identicalTrees(root, root0))
		cout<<"Same\n";
	else
		cout<<"Different\n";
	
	cout<<"In-Order Traversal: \n";
	inOrderTraversal(root);  // In-Order Traversal of Tree
	cout<<"Pre-Order Traversal: \n";
	preOrderTraversal(root); // Pre-Order Traversal of Tree
	cout<<"Post-Order Traversal: \n";
	postOrderTraversal(root); //Post-Order Traversal of Tree
	
	cout<<"\n\n\n";
	
	clearLeafNodes(root);
	cout<<"In-Order Traversal: \n";
	
	inOrderTraversal(root);  // In-Order Traversal of Tree
	cout<<"Maximum Element in Tree (recurssion): "<<maxElementInTree(root)<<"\n";
	cout<<"Maximum Element in Tree (Non-recurssion): "<<maxElementInTreeWithoutRecurssion(root)<<"\n";
	
	cout<<"Element Serching (element- 5): "<<findElement(root, 5)<<"\n";
	
	cout<<"Tree Size: "<<treeSize(root)<<"\n";
	cout<<"Tree Maximum Height: "<<maxHeight(root)<<"\n";
	
	mirrorTree(root);
	cout<<"In-Order Traversal: (After Mirroring)\n";	
	inOrderTraversal(root);  // In-Order Traversal of Tree

	//char c;
	//if(i==0)
    	//c=getchar();
	return 0;
}

/* Its Not Who I am Underneath, but What I Do That Defines Me ...*/

