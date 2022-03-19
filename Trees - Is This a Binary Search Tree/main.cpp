/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool check(Node *root, int min, int max){
        if(root == NULL)
            return 1;
        
        if(root->data <= min || root->data >= max)
            return 0;
        
        return check(root->left, min, root->data) &&
               check(root->right, root->data, max);
    }

	bool checkBST(Node* root) {
        return check(root, -1, 10001);
	}