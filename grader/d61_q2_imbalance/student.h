// Your code here

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int maxIm = 0;
    KeyT ans = mRoot->data.first;
    compute(mRoot,ans,maxIm);
    return ans;
}

int compute(node *n,KeyT &ans,int &maxIm){
    if(n == nullptr) return -1;
    int hl = compute(n->left,ans,maxIm);
    int hr = compute(n->right,ans,maxIm);
    int imbalance = abs(hl-hr);
    int h = 1 + std::max(hl,hr);
    std::cout << "IM : " << imbalance << std::endl;
    if(imbalance > maxIm || (imbalance == maxIm && n->data.first < ans) ){
        ans = n->data.first;
        maxIm = imbalance;
    }
    return h;
}
