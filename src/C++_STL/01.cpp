/*
STL is of 4 parts
1. Containers
    1. Sequntials
        1. vectors -> it+1 or it++
        2. stack
        3. queue
        4. pair(not a container)
    
    2. unordered // only increment is possible
        1. unordered_map(O(1)) -> it++ (time complexity may get to O(n) when all the element have the same hash value)
        2. unordered_set(O(1)) -> it++ (time complexity may get to O(n) when all the element have the same hash value)
    
    3. ordered // increment and decrement is possible
        1. map(O(logn)) -> it++
        2. multimap(O(logn)) -> it++
        3. set(O(logn)) -> it++
        4. multiset(O(logn)) -> it++
    
    4. nested containers
        1. vector<vector<int>>
        2. set<pair<int, string>>
        3. map<int, vector<int, int>>
        4. vector<map<int, set<int>>>

    
2. Iterator
    point to memory address of container
    - begin(), end()
    - vector<int>:: iterator it;
    - vector is continuous iterator -> means we can do it+1, it+3 etc
    - map set are not continuous there we can not do the abpve thing

3. Algorithms
    - upper bound
    - lower bound
    - sort
    - max_element
    - min_element
    - accumulator
    - reverse
    - count
    - find
    - next permutation
    - prev permutation
4. Functors
    these are the class which you can use it as function
*/
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    // 1.
    pair<int, string> p;
    p =make_pair(1, "Aryan"); // using this you can make pair directly
    // or
    p = {1, "hvsdf"};


    // 2.
    // if you try to copy one array to another it won't get copy, bcz pointer get copied and two array behave as same changing one reflects on other
    int* a= new int[9];
    int* b=a;
    b[0]=9876;
    cout<<a[0]<<endl; 

    // 3.
    // but the above scenario is not with vector
    vector<int> c;
    c.push_back(1); //O(1)
    c.pop_back();// O(1)
    vector<int> d= c;// this copy the value of c to d O(n)


    // 4.
    // (*it).next <=> it->next



    // 5.
    // three way to insert element to map, so in map every element is like pair, if using iteratir then u need to access
    /// key with .first and value with .second
    map<int, int> m;
    m[0]=26;
    m.insert({3, 89});
    m.insert(make_pair(78, 69));
    auto it = begin(m);
    cout<<(*it).first<<endl; // .first is immutable

    auto e=m.find(0); // return the iterator and if that key not present it return m.end()
    m.erase(0); // take either key or iterator(if giving iterator that should not be .end() it will give error on it)
    m.clear(); // is used to empty the map



    // 6.
    // set
    set<int> s; // have unique values
    s.insert(1); // this return pair -> .first->value .second->bool
    s.insert(2);
    s.insert(3);
    
    auto set_it = s.find(3); // return iterator else if not exits then .end() iterator get return
    int x = (*set_it); // to access the value form the iterator
    s.erase(set_it); // takes iterator or value to delete
    // unordered_set is almost same as set but it is not implemented using red black tree, and time complexity decrease to O(1)


    // 7.
    // you can not add pair vector to unordered set just like unordered map bcz to create the hash is not implemented in c++
    // another way is to use comparator so compiler make hash on your desired value

    /*
        // Custom hash function for the unordered_set
        struct CustomHash {
            size_t operator()(const Pair& p) const {
                // Hash only the .first member of the pair
                return hash<int>()(p.first);
            }
        };

        // Custom equality function for the unordered_set
        struct CustomEqual {
            bool operator()(const Pair& lhs, const Pair& rhs) const {
                // Compare only the .first members of the pairs
                return lhs.first == rhs.first;
            }
        };

        unordered_set<Pair, CustomHash, CustomEqual> mySet;
    */


   // 8.
   multiset<int> ms; // it uses black red tree implementation internally
   ms.insert(1);
   // this data structure keeps the multiple value but in sorted order all the unique elements comes at a place
   // but in unordered_multiset(as internally implemntation is of hash it can not use any data structure asa element or need to implement the hash function)
   // multiple value can be kept and all the same value comes close but there is no order in different value

   ms.erase(1); // can give argument as value(this will delete all the duplicate values also) or iterator(this will delete a particular iterator)

   /*   
        you can see the difference between bellow

        link to a que to use mltiset -> https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?purpose=login&source=problem-page&update=google

        1. 
        multiset<int> ms; // this can be used as priority queue
        ms.insert(4);
        ms.insert(3);
        ms.insert(1);
        ms.insert(4);
        ms.insert(1);
        ms.insert(5);

        auto it = ms.begin();
        while(it != end(ms)){
            cout<<(*it)<<endl;
            it++;
        }

        output -> 
        1
        1
        3
        4
        4
        5


        2.
        unordered_multiset<int> ms;
        ms.insert(4);
        ms.insert(3);
        ms.insert(1);
        ms.insert(4);
        ms.insert(1);
        ms.insert(5);

        auto it = ms.begin();
        while(it != end(ms)){
            cout<<(*it)<<endl;
            it++;
        }
        output -> 
        5
        1
        1
        3
        4
        4
   */




    // 9.
    // you can directly compare pair p1 and pair p2 (by defalut it compare .first value and when .first is equal then comparison get shift on .second)
    // this is same with set, it will compare according to first element and if same it goes to search for other where it can find different element of set
    // pair, vector, set can we directly comapre as done bellow
    vector<int> vec1;
    vec1.push_back(6);
    vector<int> vec2;
    vec2.push_back(3);
    bool bo = vec1<vec2;


    /*
    10. smae for map, set(but not in unordered as it need hash function defined)
    int main(){
        int n;
        cin>>n;
        map<pair<string, string>, vector<int>> m;
        for(int i=0; i<n; i++){
            string first, last;
            int num;
            cin>>first>>second>>num;
            for(int i=0; i<num; i++){
                int xp;
                cin>>xp;
                m[{frist, second}].push_back(xp);
            }
        }

        for(auto &pr:m){
            auto&fullname = pr.first;
            auto& listmark = pr.second;
            cout<<fullname.first<<" "<<fullname.second<<endl;
            cout<<listmark.size()<<endl;
        }
        return 0;
    }

    try for
    -> https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE
    */



   /*
   11.

    stack LIFO
        - push
        - pop
        - top (to see the top element)

    queue FIFO
        - push
        - pop
        - front

   */


  /*
  12.

  To find the next greater element, this is implemented using stack
        4, 5, 2, 25, 7, 8
        5, 25, 25, -1, 8, -1

        class Test{
            public:
                vector<int> NGE(vector<int>& vec){
                    int n=vec.size();
                    vector<int> ans(n);
                    stack<int> st;

                    for(int i=0; i<n; i++){
                        while(!st.empty() && vec[i]>vec[st.top()]){
                            ans[st.top()] = i;
                            st.pop();
                        }
                        st.push(i);
                    }

                    while(!st.empty()){
                        ans[st.top()] = -1;
                        st.pop();
                    }

                    return ans;
                }
        };

        int main(){
            Test t = Test();
            int n;
            cin>>n;
            vector<int> vec;
            while(n-->0){
                int a;
                cin>>a;
                vec.push_back(a);
            }

            vector<int> nge = t.NGE(vec); // this will copy the value of returned vect, if you want to use as reference you need to pass it as argumnet

            return 0;
        }
  */


    /*
    13. sort() function of c++
        -> take the start and end(iterator after the last iterator) iterator and do sorting between those, start->inclusive, end->exclusive
        -> use intro sort 
        -> this is the mixture of 3 sorting algo
            -> quick sort(when depth increases then it automatically get shift to heap sort), heap sort, insertion sort(used when there is less number of elements)
        -> one of the bext sorting algo
        -> comparator of sort function ask likee -> if you want to swap return false and if not retur true, so jasa chahiye vasa return kro or sab apne aap ho jyega
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
                if(a.first != b.first){
                    return a.first<b.first; // pehli value dusri value se choti honi chahiye
                }
                return a.second>b.second; // pehli value dusri value se badi honi chahiye
        };
        -> comparator can be a normal function also

    */



   /*
    14.

    lower_bound and upper_bound -> this is of O(n) time complexity when we are using it with map and set
    so while suing map and set use mp.lower_bound/upper_bound or st.lower_bound()/upeer_bound
    this work on sorted elements


    in case array and vector time complexity is O(logn)
    int a[6]={4, 5, 5, 7, 8, 25};
    int*ptr1 = lower_bound(a, a+6, 5) // ya to vo element find krega or agar vo element nhi hai to usse just bada prenst element ko find krega
    if(ptr1 == (n+6)){
        cout<<"index out of bound"<<endl; // in case of vector it will return iterator(end)
    }
    cout<<(*ptr1)<<endl;

    int*ptr2 = upper_bound(a, a+6, 8); // ye usse just bada present element return krega



    in case of set ->
    set.upper_bound(4)/lower_bound(2) -> now this is of O(logn)

    in case of map -> this is done on the key
    map.upper_bound(4)/lower_bound(2) -> now this is of O(logn)
   */



  /*
  15.
        Algorithum lib of c++
    
    vector<int> vec;
    int a[n];
    min_element(begin(vec), end(vec));
    min_element(a, a+n); // for array
    max_element(begin(vec), end(vec));


    
    for 2D array when the memory is allocated using heap
    int dp[k][k];
    int max_ = *max_element(&dp[0][0], &dp[0][0] + k * k);


    for 2D vector
    int max_ = *max_element(dp.front().begin(), dp.back().end());

    for 2D array when memory is allocated using stack
    int** arr = new int*[k];
    for(int i=0; i<k; i++){
        arr[i]=new int[k];
    }
    for (int i = 0; i < k; ++i) {
        max_ = max(max_, *max_element(arr[i], arr[i] + k));
    }
    do not forget to deallocate the memory


    to get the sum
    int sum = accumulate(begin(vec), end(vec), 0); // initial sum is also provided

    count
    int ct = count(begin(vec), end(vec), 4); // konse element ka count chahiye that is also need to be provided

    to fincd the iterator of particular element
    auto it = find(vec.begin(), vec.end(), 9);


    to reverse -> string vector array
    reverse(vec.begin(), vec.end()); // same dor string

  */


 /*
    16.
        lambda function

        auto sum = [](int a, int b){return a+b;};
        int a = sum(4, 5); // can be called as funtion\



        all_of -> to check whether all the element follow a condition or not
        all_of(vec.begin(), vec.end(), [](int& x){return x>0;}); -> to check all the element of ht earray are positive or not

        any_of -> return true if any of the element follow the condition
        none_of -> agar koi bhi match nhi krega tohi ye true return krega
 */


/*
    18.
    pointer and double pointer
        int a=10;
        int*b = &a;
        int**c = &b;
        cout<<"value of a -> a -> "<<a<<endl; // a ka value
        cout<<"address of a -> &a -> "<<&a<<endl; // a ka address
        cout<<"value of b -> b -> "<<b<<endl; // b ka value
        cout<<"addres of b -> &b -> "<<&b<<endl;// b ka address
        cout<<"value of c -> c -> "<<c<<endl; // c ka value or b ka address
        cout<<"address of c -> &c ->"<<&c<<endl; //c ka address
        cout<<"value of *c -> *c -> "<<*c<<endl; // b ka value or a ka address
        cout<<"value of **c -> **c -> "<<**c<<endl; // a value
*/



/*
    19.
        this is the way to initialize string with length of n
        string str(n, '-); means initializing each character of string with '-'
*/



/*
    20.
        void convert(Node* head, TreeNode *&root) {}
        in the above function we are passing pointer which pointes a TreeNode address
        but its not necessary that the pointer point to a valid address that address can be null also
        so for the safe side you need to create the object of the TreeNode and make the pointer to point it

*/


/*
    21. about string
        cin>>t;
        cin.ignore();
        while(t-->0){
            string s;
            getline(cin, s);
        }

        string str;
        str.push_back(); // this add a character or string at the end, using this is norw effective according to the time complexity


        some time you need to take a big integer as input of may be 10^20 length integer
        then you directly take it as string and perform the operation on each character



        if you are declaring global array then it should not be of more than 1e7
        and in local not more than 1e5
*/



/*
alternative
    
    and for &&
    and_eq for &=
    bitand for &
    bitor for |
    compl for ~
    not for !
    not_eq for !=
    or for ||
    or_eq for |=
    xor for ^
    xor_eq for ^=
*/



/*
    unordered map use the concept of hashong to store the elements, and if in case all elements have the same
    hash value then time gets increase in fetching any key

    so to make it reserve, if we already know that the unordered map is going to have the these many elements we use
    the reserve function

    so to have 2^10 reserve positions
    mp.reserve(1<<10);
 */


    return 0;
}
