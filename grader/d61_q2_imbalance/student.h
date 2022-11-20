// Your code here

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    KeyT ans = mRoot->data.first;
    int maxIm = 0;
    compute(mRoot,ans,maxIm);
    return ans;
}

void compute(node *n,KeyT &ans,int &maxIm){
    if(n == NULL) return;

    compute(n->left,ans,maxIm);

    int lh = calcHeight(n->left);
    int rh = calcHeight(n->right);
    int curIm = std::abs(rh-lh);
    if(curIm > maxIm){
        ans = n->data.first;
        maxIm = curIm;
    }

    compute(n->right,ans,maxIm);
}

int calcHeight(node *n){
    if(n==NULL) return -1;
    return 1 + std::max(calcHeight(n->left),calcHeight(n->right));
}
