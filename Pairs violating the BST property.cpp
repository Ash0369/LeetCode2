long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversionCount;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inversionCount += mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);
        inversionCount += merge(arr, temp, left, mid, right);
    }
    return inversionCount;
}

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}
vector<int>vec;
void dfs(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    dfs(root->left);
    vec.push_back(root->data);
    dfs(root->right);
}
class Solution 
{
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root)
    {
        vec.clear();
        dfs(root);
        return countInversions(vec);
    }
};
