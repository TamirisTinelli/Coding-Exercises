/*
Leet Code Problem
82. Remove Duplicates from Sorted List II
link: leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
        if (head == nullptr) return head;

        ListNode* new_head = nullptr;
        ListNode* end = nullptr;

        ListNode* atual = head;
        int last_num = -200;

        // se próximo não é vazio
        while (atual->next != nullptr) {

            ListNode* prox = atual->next;
            
            // para adicionar na lista deve ser valor unico
            // valor diferente do anterior e do próximo
            if ((atual->val != last_num) && (atual->val != prox->val)) {
                // nó entra na lista
                if (new_head == nullptr) {
                    new_head = atual;
                }
                else {
                    end->next = atual;
                }
                end = atual;
                atual->next = nullptr;
            }
            // atualiza as variáveis para próxima análise
            last_num = atual->val;
            atual = prox;
        }
        //ultimo nó da lista
        if (atual->val != last_num) {
            // nó entra na lista
                if (new_head == nullptr) {
                    new_head = atual;
                }
                else {
                    end->next = atual;
                }
                end = atual;
                atual->next = nullptr;
        }
        return new_head;
    }
};