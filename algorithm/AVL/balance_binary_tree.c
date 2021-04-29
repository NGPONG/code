#include "balance_binary_tree.h"


/** 
 * @brief LL(left-left)调整，右单旋转，顺时针旋转
 * @param 
 *  - root 最小不平衡树
 * @note 
 *  - LL调整: 新结点在某个最小不平衡树上的左子节点的左子树上进行插入的
 * 
 *  - 将根节点的左子结点变为新的根节点
 *  - 旧的根节点变为变为新的根节点的右结点，在这一步中，如果原先该位置已经存在结点，则直接替换，而被替换掉的结点则归纳为旧根节点的左子节点
*/
void right_rotate(bi_node **root) {
  bi_node *left = (*root)->left;
  (*root)->left = NULL;
  if (left->right != NULL) (*root)->left = left->right;
  left->right = *root;
  *root = left;
}

/** 
 * @brief RR(right-right)调整，左单旋转，逆时针旋转
 * @param 
 *  - root 最小不平衡树
 * @note
 *  - RR调整: 新结点在某个最小不平衡树上的右子节点的右子树上进行插入的
 * 
 *  - 将根节点的右子结点变为新的根节点
 *  - 旧的根节点变为变为新的根节点的左结点，在这一步中，如果原先该位置已经存在结点，则直接替换，而被替换掉的结点则归纳为旧根节点的右子节点
*/
void left_rotate(bi_node **root) {
  bi_node *right = (*root)->right;
  (*root)->right = NULL;
  if (right->left != NULL) (*root)->right = right->left;
  right->left = *root;
  *root = right;
}

/** 
 * @brief 左平衡旋转处理，该函数的主要目的是集成修改最小不平衡树中结点的 bf 的功能
 * @param
 *  - root 最小不平衡树
*/
void left_balance(bi_tree **root) {
  bi_tree *l_r_tree;
  bi_tree *l_tree;

  l_tree = (*root)->left;
  switch (l_tree->bf) {
    /**
     * 判断最小不平衡树 [root] 的左子树的平衡因子来决定到底是需要 LL(右)旋 还是 LR(先左后右)旋.
     * 
     * 由于该函数是左平衡旋转的处理，所以判断是以根节点(最小不平衡树)的左子树为出发点
     * 来进行，并且，判断的标准无非就是两个
     *  - 根节点的左子节点的左子树高: 即符合右单旋转的前提条件，即新结点在某个最小不平衡树上的左子节点的左子树上进行插入的
     *  - 根节点的左子结点的右子树高: 即符合LR旋转的前提条件，即新节点在某个最小不平衡树上的左子结点的右子树上进行插入的
     *  - 这里不存在根节点的左子节点左右树等高的情况，因为必定是因为某个新节点的插入，才导致了这颗树的深度的增加，而正因为树
     *    的深度的增加这个前提条件，才导致了是否需要对该出现不平衡的最小不平衡树进行旋转处理
     * 
     * 对于每种情况所改变的 [bf] 的规则，可以自己在本子上演练一遍，并统计结果的 [bf] 即可，最关键的是要掌握旋转的规则
    */

  case L_H:
    /* 右单旋转，所改变的结点仅为 [根节点] 和 [跟结点的左孩子结点]，故仅需要调整其二者的 bf 即可 */
    (*root)->bf = l_tree->bf = E_H;
    right_rotate(root);
    break;
  case R_H:
    l_r_tree = l_tree->right;

    /* LR旋转，需要考虑 [根节点的左孩子的右子树] 的问题，即这里又涵盖了一层 switch，这种旋转方式需要把 [根节点的左孩子的右子树] 和 [剩下的树] 切分开来考虑 */

    /* 对于 LR 旋转来说，该旋转会影响三种结点，分别是 [根节点], [跟结点的左孩子结点], [根节点的左孩子的右孩子] */

    switch (l_r_tree->bf) {
    case L_H:
      (*root)->bf = R_H;
      l_tree->bf = E_H;
      break;
    case R_H:
      (*root)->bf = E_H;
      l_tree->bf = L_H;
      break;
    case E_H: /* 其实我觉得这种情况应该是不存在的，但是不知道为什么《大话数据结构》里面要这么考虑 */
      (*root)->bf = l_tree->bf = E_H;
      break;
    }
    l_r_tree->bf = E_H;
    left_rotate(&(*root)->left);
    right_rotate(root);
    break;
  }
}

/** 
 * @brief 右平衡旋转处理，该函数的主要目的是集成修改最小不平衡树中结点的 bf 的功能
 * @param
 *  - root 最小不平衡树
*/
void right_balance(bi_tree **root) {
  bi_tree *r_l_tree;
  bi_tree *r_tree;

  r_tree = (*root)->right;
  switch (r_tree->bf) {
    /**
     * 判断最小不平衡树 [root] 的右子树的平衡因子来决定到底是需要 RR(左)旋 还是 RL(先右后左)旋.
     * 
     * 由于该函数是右平衡旋转的处理，所以判断是以根节点(最小不平衡树)的右子树为出发点
     * 来进行，并且，判断的标准无非就是两个
     *  - 根节点的右子节点的左子树高: 即符合左单旋转的前提条件，即新结点在某个最小不平衡树上的右子节点的右子树上进行插入的
     *  - 根节点的右子结点的右子树高: 即符合RL旋转的前提条件，即新节点在某个最小不平衡树上的右子结点的左子树上进行插入的
     *  - 这里不存在根节点的左子节点左右树等高的情况，因为必定是因为某个新节点的插入，才导致了这颗树的深度的增加，而正因为树
     *    的深度的增加这个前提条件，才导致了是否需要对该出现不平衡的最小不平衡树进行旋转处理
     * 
     * 对于每种情况所改变的 [bf] 的规则，可以自己在本子上演练一遍，并统计结果的 [bf] 即可，最关键的是要掌握旋转的规则
    */

  case R_H:
    /* 左单旋转，所改变的结点仅为 [根节点] 和 [跟结点的右孩子结点]，故仅需要调整其二者的 bf 即可 */
    (*root)->bf = r_tree->bf = E_H;
    left_rotate(root);
    break;
  case L_H:
    r_l_tree = r_tree->left;

    /* RL旋转，需要考虑 [根节点的右孩子的左子树] 的问题，即这里又涵盖了一层 switch，这种旋转方式需要把 [根节点的右孩子的左子树] 和 [剩下的树] 切分开来考虑 */

    /* 对于 RL 旋转来说，该旋转会影响三种结点，分别是 [根节点], [跟结点的右孩子结点], [根节点的右孩子的左孩子] */

    switch (r_l_tree->bf) {
    case L_H:
      (*root)->bf = E_H;
      r_tree->bf = L_H;
      break;
    case R_H:
      (*root)->bf = L_H;
      r_tree->bf = E_H;
      break;
    case E_H: /* 其实我觉得这种情况应该是不存在的，但是不知道为什么《大话数据结构》里面要这么考虑 */
      (*root)->bf = r_tree->bf = E_H;
      break;
    }
    r_l_tree->bf = E_H;
    right_rotate(&(*root)->right);
    left_rotate(root);
    break;
  }
}

/** 
 * @brief 平衡二叉树结点插入
 * @param 
 *  -   tree 平衡二叉树
 *  -    val 值
 *  - taller 指示当前所插入的结点是否令树的高度增加
*/
bool insert_AVL(bi_tree **tree, int val, bool *taller) {
  if (!*tree) {
    *tree = (bi_tree *)malloc(sizeof(bi_node));
    (*tree)->data = val;
    (*tree)->left = (*tree)->right = NULL;
    (*tree)->bf = E_H;
    *taller = true;
  } else {
    if (val == (*tree)->data) {
      *taller = false;
      return false;
    }

    if (val < (*tree)->data) {
      if (!insert_AVL(&(*tree)->left, val, taller))
        return false;

      if (*taller) {
        switch ((*tree)->bf) {
        case L_H:
          left_balance(tree);
          *taller = false;
          break;
        case E_H:
          (*tree)->bf = L_H;
          *taller = true;
          break;
        case R_H:
          (*tree)->bf = E_H;
          *taller = false;
          break;
        }
      }
    } else {
      if (!insert_AVL(&(*tree)->right, val, taller))
        return false;

      if (*taller) {
        switch((*tree)->bf) {
          case L_H: /* 原先该节点的 bf 是 1，并且此次插入操作是针对该节点的右子结点进行插入的，那不就意味着此次插入并没有改变父节点的 bf 嘛 */
                    /* 并且，既然原先在这个高度下就没有达成最小生成树的条件，那么高度不变的话，上层递归的函数就不需要再进行判断了 */
            (*tree)->bf = E_H;
            *taller = false;
            break;
          case E_H: /* 原先该节点的 bf 是 1，并且此次插入操作是针对该节点的右子结点进行插入的，那不就意味着此次插入使得树的高度增加了 1 嘛，所以父节点的 bf = -1 */
                    /* 那是否证明其根节点的 bf 的绝对值一定 >=0 && <= 1 呢？这是不确定的，故这里还要再上层递归中进行判断 */
            (*tree)->bf = R_H;
            *taller = true;
            break;
          case R_H: /* 既然原先该节点的 bf 是 -1 了，那么此次增加的结点造成了树的高度的增加，所以该结点就属于最小不平衡树的根节点 */
            right_balance(tree);
            *taller = false;
            break;
        }
      }
    }
  }

  return true;
}