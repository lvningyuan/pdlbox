#include <stdio.h>
#include <iostream>
#include <stack>

//结点的组成
template <class T>//类似于模板类  ，模板结构体
struct BSTNode
{
  BSTNode(const T& data)
    :pLeft_(nullptr)
     ,pRight_(nullptr)
     ,pParent_(nullptr)
     ,data_(data)
     ,buf_(0)
  {}

  BSTNode<T>* pLeft_;
  BSTNode<T>* pRight_;
  BSTNode<T>*  pParent_;
  T data_;
  int buf_;//平衡因子
};


template <class T>
class BSTree
{
  typedef BSTNode<T> Node;//取别名
  typedef Node* PNode;//结点指针
  
  public:

  BSTree()
  :pNode_(nullptr)
  {}


  //后序递归销毁
 void Destroy(PNode pRoot_)
{
  if(pRoot_->pLeft_ == nullptr  && pRoot_->pRight_ == nullptr)
    {
      free(pRoot_);
      pRoot_ = nullptr;//这一步还是很重要要的，1避免出现野指针，2  使递归回归时能正常进行
      return ;
    }

      if(pRoot_->pLeft_)
        Destroy(pRoot_ ->pLeft_);
      if(pRoot_ ->pRight_)
        Destroy(pRoot_->pRight_);
}

~BSTree()
{ 
  Destroy(); 
}


      //用二叉搜索树的特性查找 data 元素 ，找到返回位置指针 ，未找到 返回nullptr
  //Find1 递归 //数据大 ，性能差 
PNode Find1(const T& data)const 
{
     if(pNode_ == nullptr)
     {
       return nullptr;
     }

     PNode tmp =pNode_;
     if(tmp->data_ == data)
     {
       return tmp;
     } 
    
     else if(tmp->pLeft_ ==nullptr && tmp->pRight_ == nullptr)
     {
       return nullptr;
     }
      else if(tmp->pLeft_ == nullptr && tmp->data_ >data )
      {
        return  nullptr;
      }
      else if(tmp->pRight_ == nullptr && tmp->data_ < data)
      {
        return nullptr;
      }
    else if(data > pNode_->data_)
    {
      tmp = tmp->pRight_;
      Find (data); 
    }

    else 
    {
      tmp = tmp ->pLeft_;
      Find(data);
    }
}

//Find  非递归
PNode Find(const T& data)
{
  if (pNode_ == nullptr)
    return nullptr;

  PNode cur = pNode_;
  while(cur)
  {
      if(cur->data_ == data )
        return cur;
      else if(cur-> data_ > data)
      {
        cur = cur->pRight_ ; 
      }

      else 
      {
        cur = cur ->pLeft_;
      }
  }
  return cur;
}


//我们  为了容器而实现红黑树 ，所以保证接口一至  bool 
    bool insert(const T& data)
{
  //1  空树
  if(pNode_ ==nullptr)
  {
     pNode_ = new PNode(data);
    return true;
  }

    PNode parent  = nullptr;//原来红黑树中不存在data， 就要插入data，并和原树 关联
    PNode  cur =pNode_;
  //2  比根小
    while(cur)//一直一直找 ，找到当前树为空的情况     
    {
      parent = cur;//提前保存双亲的位置

      if(data < cur->data_)
      {
        cur =  cur->pLeft_;
      }
      else if(data > cur->data_)
      {
        cur = cur->pRight_;
      }
      else//说明存在 
      {
        return false;
      }
    }
      //走到这里说明data不存在 ，找到了自己该待的位置了
      PNode tmp = new PNode(data);
      //给自己找双亲
     if(data > parent->data_) 
       parent->pRight_ = tmp;
     else 
       parent->pLeft_ = tmp;

      return true;
    }

bool erase(const T& data)
{
  PNode ret  = Find(data);
  if(ret == nullptr)
  {
    perror("不存在 data");
    return false;
  }
  
  if(ret->pLeft_ == nullptr && ret->pRight_ ==nullptr)//只有一个根节点
  {
      delete ret;
      return true;
  }
  else if(ret ->pLeft_ == nullptr)//左子树为空
  {
    PNode tmp = ret->pRight_;
    delete ret;
    ret =tmp;
    return true;
  }
  else if(ret->pRight_ == nullptr) //右子树为空
  {
    PNode tmp = ret ->pLeft_;
    delete ret;
    ret = tmp;
    return true;
  }
          //左右子树都存在，直接删，不好删，需要调整好多结点的位置，换种思想   删除替代结点的方式---删除左子树最大的结点，先交换值
          //或者 删除右子树最小的结点 ，也需要先交换值

  else //左右子树都存在
  {
    PNode  tmp = ret->pLeft_;
    PNode parent = nullptr;
    while(tmp)
    {
      parent = tmp;
      if(tmp->pRight_)
        tmp = tmp->pRight_;
      else 
        tmp = tmp->pLeft_;
    }

    ret->data_ =  parent->data_;
    delete parent;
    return true;
  }
}


//中序遍历
void Inorder( PNode& pNode_ )const 
{
  
  PNode cur = pNode_;

  if( cur == nullptr)
      return ;
  Inorder(pNode_->pLeft_);
  std::cout<<cur->data_<<"  ";
  Inorder(pNode_->pRight_);
  
}


//非递归 
void Inorder2()
{
  std::stack<std::pair<PNode,bool> >s;

  s.push(make_pair(pNode_,false));//相当于 用  true  标记了 每一层的根节点
  while(!s.empty())
  {
      PNode tmp = s.top().first;
      bool ret = s.top().second; 
      s.pop();
      if(tmp == nullptr)//当前结点为空 ，则跳过
      {
        continue;
      }

      if(ret)//查看标记
      {
        std::cout<<tmp->data_<<"  ";
      }
      else//注意栈 的 特性  
      {
        s.push(make_pair(tmp->pRight_,false));
        s.push(make_pair(tmp,true));//根结点用 true 标记
        s.push(make_pair(tmp->pLeft_,false));
      }
  }

}





//四种情况需要 旋转处理

//1  左左   右单旋
void rotateR(PNode parent)
{

  //插入左左 ，旋转 左右
  PNode subL = parent->pLeft_;//备份 左子树
  PNode subLR = subL->pRight_;  // 备份 左子树的右子树
  
  parent->pLeft_  = subLR;//   1  .将左孩子的右孩子赋值给  根的左孩子 

  if(subLR != nullptr)//  
  { 
    subLR->pParent_ = parent;//     更新他的父节点指向
  }
    
  subL->pRight_ = parent;   //  2   将根剪切到subLR的位置
  
  parent->pParent_ = subL;//更新 parent 当前的父节点

  PNode ppParent = parent->pParent_;//原来的父节点
  subL->pParent_ = ppParent;    //  更新父节点


  if(ppParent  == nullptr)//  3   若 parent 结点为根节点
  {         
    pNode_ = subL;
    subL->pParent_ = nullptr; //  更新父节点
  }
                                //  4 parent 非根，更新其父节点的相应子树指针
  else//不是根,parent可能是他栓亲的左子树 ， 也可能是双亲的右子树
  {
      if(ppParent->pLeft_ == parent )//是双亲的左孩子
        ppParent->pLeft_  = subL;
      else 
        ppParent ->pRight_ = subL;
  }

  parent->buf_ = subL->buf_  = 0;//当亲调整后平衡因子为0 
}


//2  右右 ---- 左单旋
void rotateL(PNode parent)
{
    //插入右右 ，旋转右左
    PNode subR  = parent->pLeft_;
    PNode subRL = subR->pLeft_;

    parent ->pLeft_ = subRL;

    if(subRL != nullptr)
    {
        subRL->pParent_ = parent;
    }
    
    
    subR->pLeft_  = parent;

    parent->pParent_ = subR;

    PNode ppParent = parent->pParent_;
    subR->pParent_  = ppParent;

    if(ppParent == nullptr)//parent  为根
    {
      pNode_ = subR;
      subR->pParent_ = nullptr;
    }

    else //  parant 不为根结点
    {
      if(parent == ppParent->pLeft_)
      {
        ppParent->pLeft_ = subR;
      }
      else 
      {
        ppParent ->pRight_ = subR;
      }
    }
}
//3    插入较高左子树的右子树    先左单旋  ，再右单旋
void rotateLR(PNode parent)
{

  PNode subL = parent->pLeft_;
  PNode subLR = subL->pRight_;

  int buf = subLR->buf_;

  rotateL(parent->pLeft_);

  rotateR(parent);

//根据插入后 subLR的 平衡因子  调整其他平衡因子 ，变为0 的平衡因子不用处理，我们在后序函数中统一处理

  if(buf == 1)//  subLR 右边高,
  {
    subL->buf_ = -1;//旋转之后, subLR 称为  sub 的左子树
  }

  else if(buf == -1) 
  {
    parent->buf_ = 1;
  }
  else //   插入后 平衡因子是0  //不存在，既然需要旋转处理 ，那一定是平衡因子出问题 ，而且只能是插入结点的爷爷结点为平衡因子为+2  / -2，
       // 那么插入节点的父节点平衡因子== +1 / -1                //因我们处理平衡因子 是从底向上处理的
  { ; }
}


//4 插入到较高右子树的左子树 --- 右左   先 右旋转 ，再左旋转
void rotateRL(PNode parent)
{
  PNode subR = parent->pRight_;
  PNode subRL = subR->pLeft_;

  int buf = subRL ->buf_;

  rotateR(parent->pRight_);
  rotateL(parent);
  
  if(buf == 1)
  {
      parent->buf_ = -1;
  }

  else if(buf == -1)
  {
    subR->buf_ = 1;
  }
}


//  原理   AVL树的插入原理 
//    1   像二叉搜索树那样 正常插入 
//    2   插入成功之后 可能会导致原有节点的 平衡因子 发生变化  ，所以要进行调整平衡因子
//    3   插入后平衡因子 可能 会有 0  -1   1   2  -2 这几种情况  
//    ，若为 0  则正常 退出 ，  
//       若为1  -1  则进行向上调整平衡因子
//       若为 2  -2   说明 该问题一定发生在 爷爷节点上 ，进行旋转处理

bool Insert(const T& data)
{
    int ret = insert(data);
    if(ret  == false)
    {
      std::cout<<"data  已存在"<<std::endl;
      return  true;
    }
  //  否则插入成功
   
    PNode  cur =    Find(data);
    PNode  parent = cur->pParent_;
   
    while(parent)
   {

     //出入到 父节点哪边，平衡因子做相应的调整
      if(cur == parent->pLeft_ )
          --(parent->buf_);

      else                    
          ++(parent->buf_);

      if(parent->buf_ == 0)//正常
      {
          break;//一切正常 ,   原有所有的节点的平衡因子都不用处理，   结束
      }

      else if(parent ->buf_ == -1 || parent->buf_ == 1)//说明 插入前双亲为根的二叉树平衡因子 0  ，插入后 多了一层，因此需要向上调整
      {
          parent = parent->pParent_;
      }
          // 平衡因子为 2  或者 -2  只可能出现在 插入节点的 爷爷节点上
      else if(parent ->buf == 2)//插入到了右边，需要调整 ，接着判断 1  右旋 ?   2  先右旋再左旋?
      {
          if(cur == (parent->pRight_)->pRight_)//插入 右右  ，右旋转
            rotateL(parent);
        
          else // 插入 右 左       先右旋转 ，再左旋转
            rotateRL(parent);

          //继续向上调整
          parent = parent->pParent_;  
      }


      else //    只可能是 -2,   判断 左旋 还是 先左  后右
      {
          
          //插入到左子树的左子树     右旋转  
          if(cur == (parent->pLeft_)->pLeft_) 
            rotateR(parent);
         
          else //  插入到左子树的右子树    先 左旋转 再右旋转
            rotateLR(parent);
        
        //继续向上调整  
            parent = parent->pParent_;
      }

   }
}
private:

    PNode pNode_;
};
