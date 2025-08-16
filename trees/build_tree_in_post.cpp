
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};



Node* buildTree(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>& inmap){
    if(is>ie || ps>pe)return nullptr;

    Node* root = new Node(postorder[pe]);

    int inRoot = inmap[postorder[pe]];
    int numsLeft = inRoot - is;

    root->left = buildTree(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,inmap);
    root->right = buildTree(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,inmap);

    return root;
}

Node* getBinaryTree(vector<int>&inorder,vector<int>&postorder)
{
  if(inorder.size()!=postorder.size())return nullptr;  
  map<int,int> inmap;
  for(int i=0;i<inorder.size();i++){
    inmap[inorder[i]]=i;
  }
  return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmap);
}





















void generateArray(Node* root, vector<int>&ans){
    if(root==NULL){
        ans.push_back(-1);
        return;
      }
    ans.push_back(root->val);
    generateArray(root->left,ans);
    generateArray(root->right,ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        assert(n<=1000000);
        vector<int>arr1(n);
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        vector<int>arr2(n);
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        Node* tree = getBinaryTree(arr1,arr2);
        vector<int>ans;
        generateArray(tree,ans);
        for(auto v:ans)cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}
