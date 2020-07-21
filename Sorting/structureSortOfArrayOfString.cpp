/*:::::::::::::::::::::::::::::::::Structure Sort for Array Of String:::::::::::::::::::::::::::::
  Sort() funciton uses Quick Sort Algorithm. Average Complexity: O(n*log(n)), In worst case Complexity: O(n^2)
*/

bool cmp(string a, string b)
{
    if(a.size()!=b.size())
        return a.size()<b.size();
    return a<b;
}


vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), cmp);  // Sort the unsorted list of string
    return unsorted;

}
