#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node* new_node(int data)
{
    node *temp=new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* insert_node(node * root, int data)
{
    if(!root)
        root = new_node(data);
    else
    {
        if(root->data<data )root->right= insert_node(root->right,data);
        else root->left=insert_node(root->left,data);
    }
    return root;
}
void inoder(node*root)
{
    if(root)
    {
        inoder(root->left);
        cout<<root->data<<" ";
        inoder(root->right);
    }
}
bool search_node(node *root,int data)
{
    if(root->data==data) return true;
    if(root->data<data) return search_node(root->right,data);
    else return search_node(root->left,data);
}
node* inoder_predecessor(node *root)
{
    node *temp=root->left;
    while(temp->right)
        temp=temp->right;
    return temp;
}
node* delete_node(node *root,int data)
{
    if(root==NULL)
    {
        cout<<"node not found\n";
        return NULL;
    }
    if(root->data == data)
    {
        if(root->left==NULL && root->right == NULL)
        {
            cout<<"root to be deleted with data node = "<<root->data<<endl;
            delete root;
            return NULL;
        }
        else if ( root->left&&root->right == NULL)
        {
            cout<<"root to be deleted with data = "<<root->data<<endl;
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right && root->left==NULL)
        {
            cout<<"root to be delete with data = "<<root->data<<endl;
            node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            node *temp = inoder_predecessor(root);
            root->data = temp->data;
            root->left = delete_node(root->left,temp->data);
        }
    }
    else if (root->data<data)
    {
        root->right=delete_node(root->right,data);
    }
    else root->left = delete_node(root->left,data);
}
int min_bst(node* root)
{
    while(root->left) root= root->left;
    return root->data;
}
int  max_bst(node* root)
{
    while(root->right) root= root->right;
    return root->data;
}
node* bst_lca(node* root, int a,int b)
{
        if(a<root->data && b<root->data)
            return bst_lca(root->left,a,b);
        else if(a>root->data && b>root->data)
            return bst_lca(root->right,a,b);
        return root;
}
int distance_bst(node* root,int a)
{
    if(root->data == a) return 0;
    else if(root->data<a) return 1+ distance_bst(root->right,a);
    else return 1+ distance_bst(root->left,a);
}
int dis_lca(node* root,int a,int b)
{
    node*temp = bst_lca(root,a,b);
    return distance_bst(temp,a)+distance_bst(temp,b);
}
int bst_height(node* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 0;
    else return max(bst_height(root->left),bst_height(root->right))+1;
}

int main()
{
    int t,p;
    cin>>t;
    while(t--)
    {
        node *root = NULL;
        int n;
        cout<<"enter the no. of nodes to be inserted\n";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            root = insert_node(root,p);
        }
        inoder(root);
        cout<<"\nhow many nodes to be searched\n";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            if(search_node(root,p))
            {
                cout<<"node found \n";
            }
            else cout<<"node not found\n";
        }
        cout<<"how many nodes to be deleted\n";
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p;
            root=delete_node(root,p);
            inoder(root);
            cout<<endl;
        }
       /* cout<<"minimum element in tree = "<<min_bst(root)<<endl;
        cout<<"minimum element in tree = "<<max_bst(root)<<endl;
        cout<<"enter two nodes to find lowest common ancestor\n";
        int a,b;
        cin>>a>>b;
        cout<<"lowest common ancestor = "<<bst_lca(root,a,b)->data<<endl;
        cout<<"minimum distance between two nodes\n";
        cin>>a>>b;
        cout<<" === "<<dis_lca(root,a,b)<<endl;
        */
        cout<<"height of the tree = "<<bst_height(root)<<endl;
    }
    return 0;
}
