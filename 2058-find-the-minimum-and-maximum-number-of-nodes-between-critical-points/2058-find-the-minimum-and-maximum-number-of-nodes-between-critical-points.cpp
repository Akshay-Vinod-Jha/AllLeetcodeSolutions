class Solution {
public:
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> remme;
    int indexis = 2; 

    ListNode* current = head; 
    int prev = current->val; 

    current = current->next; 

    while(current->next != nullptr){ 

        int next = current->next->val; 
        int cvalue = current->val; 

        if(cvalue > prev && cvalue > next) 
            remme.push_back(indexis); 

        else if(cvalue < prev && cvalue < next) 
            remme.push_back(indexis); 

        prev = cvalue; 
        current = current->next; 
        indexis++; 
    } 
     
    int size = remme.size(); 

    if(size < 2) 
        return {-1, -1}; 

    int minimum = INT_MAX; 

    for(int i = 1; i < size; i++){ 
        minimum = min(minimum, remme[i] - remme[i - 1]); 
    } 

    return {
        minimum,
        remme[size - 1] - remme[0]
    }; 
} 

};
