/*
Leet Code Problem
83. Remove Duplicates from Sorted List
link: leetcode.com/problems/remove-duplicates-from-sorted-list

solution by: Tamiris Tinelli
Date: 01/May/2024
Time Complexity: O(log n)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // lista vazia
        if (head == nullptr) return head;
        
        ListNode* atual = head; // ponteiro atual
        int num_atual = atual->val; // valor atual

        ListNode* prox = nullptr; // ponteiro proximo
        int num_prox = 0; // valor do proximo

        while(atual->next != nullptr) {
            prox = atual->next;
            num_prox = prox->val;

            // verifica se o prox será excluído
            if (num_prox == num_atual) {
                // deleta prox
                // atual segue o mesmo, prox é atualizado
                atual->next = prox->next;
            }
            else {
                // não deleta prox
                // prox se torna atual
                atual = prox;
                num_atual = atual->val;
            }
        }
        return head;
    }
};