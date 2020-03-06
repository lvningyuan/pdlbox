#include <iostream>

enum  Color{RED, BLACK};

template <class T>
struct RBTreeNode
{
  RBTreeNode(const T& data = T() , Color color = RED)
    :pLeft_(nullptr)
     ,pRight_(nullptr)
     ,pParent_(nullptr)
     ,data_(data)//平衡因子
     ,color_(color)//默认是红色结点 ，因为黑色节点必然会影响自平衡
  {}


  RBTreeNode<T> * pLeft_;
  RBTreeNode<T> * pRight_;
  RBTreeNode<T> * pParent_;
  T data_;
  Color color_;
};


// 红黑树实在二叉搜索树的基础上增加 平衡条件， 因此 红黑树的插入分两步， 1  二叉搜索树的插入 ，  2  平衡调整


//注意 ，为了实现后续的关联式容器 ，我们在红黑树的实现中加上了 Head_  头节点   Root->pParent_ ==  Head
template <class T>
class RBTree 
{

  typedef RBTreeNode<T>  Node;
  typedef Node* PNode;

  public:





  //右旋
  //我这里命名不科学，切勿自带感情 ，参数grandpa 最好用 pNode 代替
  void rotateR1(PNode& grandpa)
  {
    PNode ggrandpa = grandpa->pParent_;//爷爷的父亲
    PNode parent = grandpa->pLeft_; 
    PNode uncle = grandpa ->pRight_;

    grandpa->pLeft_ = parent->pRight_;
    parent->pRight_= grandpa;
    parent->pParent_ = ggrandpa;
    grandpa->pParent_ = parent;

    //更改 ggrandpa 的指向
    //  3 种情况   ggrandpa 为 head   2  不为head ，但是grandpa为其左子树  3  为其右子树
    if(grandpa == ggrandpa->pLeft_)
      parent = ggrandpa->pLeft_;
    else if(grandpa == ggrandpa ->pRight_)
      parent = ggrandpa->pRight_;
    else 
      parent = ggrandpa->pParent_;
  }

  void rotateR(PNode& pNode)//参数为要被旋转的结点
  {
    PNode parent   = pNode->pParent_;//要旋转节点的父节点
    PNode newHead = pNode->pLeft_;

    pNode->pLeft_ = newHead->right;
    newHead->pRight_ = pNode;
    pNode->pParent_ = newHead;
    newHead->pParent_ = parent;

    if(pNode == parent->pLeft_)
      parent->pLeft_ = newHead;
    else if(pNode == parent ->pRight_)
      parent->pRight_ = newHead;
    else 
      parent ->pParent_ = newHead;


  }
  //左旋
  void rotateL(PNode& pNode)
  {
    PNode  parent  =pNode;
    PNode  cur  = pNode->pRight_;
    PNode grandpa = parent->pParent_;

    parent->pRight_ = cur->pLeft_;
    cur->pLeft_ = parent;
    cur->pParent_ = parent->pParent_;
    parent->pParent_ = cur;

    if(grandpa->pLeft_  == grandpa)
      grandpa->pLeft_ = parent;
    else if(grandpa->pRight_ == grandpa)
      grandpa->pRight_ = parent;
    else 
      grandpa->pParent_ = parent;

  }



  //下边这种写法不好
  void rotateL1(PNode grandpa)
  {
    PNode ggrandpa = grandpa->pParent_;//爷爷的父亲
    PNode parent = grandpa->pLeft_; 
    PNode uncle = grandpa ->pRight_;

    grandpa->pRight_ = parent->pLeft_;
    parent->pLeft_ = grandpa;
    parent->pParent_ = ggrandpa;
    grandpa->pParent_ = parent;

    if(grandpa == ggrandpa->pLeft_)
      parent = ggrandpa->pLeft_;
    else if(grandpa == ggrandpa ->pRight_)
      parent = ggrandpa->pRight_;
    else 
      parent = ggrandpa->pParent_;
  }


  bool Insert(const T& data)
  {
    PNode pRoot = GetRoot();
    //双亲为空
    if(pRoot == nullptr)   //空树
    {
      pRoot = new RBTree (data,RED);

      pRoot ->pParent_ = pHead_;
      pHead_->pParent_ = pRoot;
    }
    else//不是空树 
    {
      //1  像二叉搜索树那样 先插入 ，
      //2 可能进行相应的旋转，调色
      PNode cur = pRoot;
      PNode parent = nullptr;
      while(cur)
      {
        parent = cur;//保存双亲，方便后期插入节点时进行连接
        if(cur->data_ > data)
        {
          cur =cur ->pLeft_ ;             
        }
        else if(cur->data_ < data)
        {
          cur = cur->pRight_;
        }
        else 
        {
          std::cout<<"data 已存在，插入失败"<<std::endl;
          return false; 
        }
      }


      //cur == nullptr  即这里就是应该插入的位置  插入节点 并进行链接
      cur = new PNode (data,RED);
      cur->pParent_ = parent;

      if(cur->data_ < parent->data_)
        cur = parent->pLeft_;
      else 
        cur = parent->pRight_;
      //插入节点完成,  进行判断是否需要 旋转 + 改色 调整


      //1  parent  不存在，即 空树 
      //直接处理跟颜色即可

      //2  parent  存在 ，parent 为黑色
      //直接插入，不需要 调整

      //3  parent 存在（即不是空树）  并且cur父亲为红色，叔叔为红色

      //4  parent  存在 ，叔父不同色，  ----------直线型
      //1  自己是父亲的左子树，  父亲是爷爷的左子树，      
      //2  自己是父亲的右子树，  父亲是爷爷的右子树，   

      //5  parent  存在 ，  叔父不同色  ---------- √型
      //1   ，自己是父亲的右子树，  父亲是爷爷的左子树         
      //2     自己是父亲的左子树，  父亲是爷爷的右子树


      //注意 ，插入的结点一定是红色结点，能走到这里 ，说明不是空树，也不是只有根结点的树，所有 grandpa 必定存在
      while(parent)
      {
        PNode grandpa = parent->pParent_;
        PNode uncle;
        if(parent == grandpa->pLeft_)
          uncle = grandpa->pRight_;
        else  
          uncle = grandpa->pLeft_;


        //3 叔父 同红    --向上调整
        if( parent->color_ == uncle->color_ ) 
        {
          parent->color_ = BLACK;
          uncle->color_  = BLACK;
          grandpa->color_= RED;
          parent = grandpa;
        }

        //4  +  5      叔不存在或者 叔父不同色 
        else if(!uncle || parent->color != uncle->color_) 
        {
          //1  确定形状   -- 左右型，  左左型  右左型，右右型  或者 直线型， √型         
          //2  选择旋转方案
          if(parent == grandpa->pLeft_  && cur == parent->pRight_)  //  √型    将grandpa右旋
          { 
            //先左旋，再右旋
            rotateL(parent);//左旋形成执行行
            rotateR(grandpa);
            //调色
            grandpa->color_ = RED;
            parent->color_ = BLACK;
          }

          else if(parent == grandpa->Right_  && cur == parent->pLeft_)//  √型    parent 左旋
          {
            rotateR(parent);//右旋形成直线型
            rotareL(grandpa);
            // 调色
            grandpa ->color_ = RED;
            cur->color_ = BLACK;
          }
          else if(parent == grandpa->pLeft_ && cur == parent ->pLeft_ )//     直线型   左直线
          {
            rotateR(grandpa);
            parent->color_ = BLACK;
            grandpa ->color_ = RED;
          }

          else                                                       //直线型    右直线
          {
            rotateL(grandpa);
            parent->color = BLACK;
            grandpa->color_ =RED;
          }

        }
      }
    }
    pRoot->color_ = BLACK;
    pHead_->pLeft_ = GetLeftMost();
    pHead_->pRight_ = GetRightMost();

  }




  private: 
  PNode& GetRoot()
  {
    return pHead_->pParent_;
  }
  PNode& GetLeftMost()
  {
    PNode cur = pHead_->pParent_; //获取根节点 
    while(cur)
    {
      if(cur->pLeft_)
      {
        cur = cur->pLeft_;
      }
      else if(cur->pRight_)
      {
        cur = cur->pRight_;
      }
      else 
        return cur;
    }
  }


  PNode& GetRightMost()
  {
    PNode cur = pHead_->pParent_;
    while(cur)
    {
      if(cur->pRight_)
      {
        cur = cur->pRight_;
      }
      else if(cur->pLeft_)
      {
        cur = cur ->pLeft_;
      }
      else 
        return cur;
    }
  }



  //检查是否为红黑树
  bool IsRBTree()
  {

    PNode cur = GetRoot();

    if(! cur) //空树
    {
      std::cout<<"满足"<<std::endl;
      return true;
    }

    else if( cur ->color_ != BLACK )
    {
      std::cout<<"根节点颜色不满足 "<<std::endl;
      return false;
    }
    else 
    {
      //  获取 任意一条路径上黑色叶子个数
      int black_count =0;
      while(cur)
      {
        if(cur && cur->color_ == BLACK)
          ++black_count;

        cur = cur->pLeft_;
      }
      int k = 0;
      return IsEqualpath(black_count, k ,GetRoot());
    }
  }


  bool IsEqualpath(int bk, int k, PNode pRoot)
  {
    // 终止条件
    if(pRoot == nullptr) 
    {
      if(k != bk)
      {
        std::cout<<"存在路径黑色节点不相等的情况"<<std::endl;
        return false;
      }
      return true;
    }

    if( pRoot == BLACK ) 
    {
      ++k;
    }

    // 不是黑色就是v红色结点，红色结点需要判断 是否存在相连通红
    else 
    {
      PNode parent = pRoot->pParent_;
      if(parent  && parent->color_ == RED)
      {
        std::cout<<"存在相邻同为红色的结点，因此不是红黑树"<<std::endl;
        return false;
      }

      return IsEqualpath(bk,k, pRoot->pLeft_)  && 
        IsEqualpath(bk,k ,pRoot->pRight_);
    }
  }

  private:
  PNode pHead_;//红黑树根节点
};


int main()
{


}

