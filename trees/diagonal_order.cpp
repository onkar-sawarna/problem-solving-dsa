#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> getDiagonalLevelorderTraversal(Node* root) {
    vector<vector<int>> answer;
    if(root == nullptr) return answer;
    queue<Node*> current_diagonal, next_diagonal;
    current_diagonal.push(root);
    while(!current_diagonal.empty()){
        vector<int> current_diagonal_elements;
        while(!current_diagonal.empty()){
            Node* curr = current_diagonal.front();
            current_diagonal.pop();
            while(curr!=nullptr){
                current_diagonal_elements.push_back(curr->val);
                if(curr->left!=nullptr){
                    next_diagonal.push(curr->left);
                }
                curr = curr->right;
            }
        }
        answer.push_back(current_diagonal_elements);
        swap(current_diagonal, next_diagonal);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}










Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        vector<vector<int>> ans = getDiagonalLevelorderTraversal(tree);
        for(auto u:ans){
            for(auto v:u){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
