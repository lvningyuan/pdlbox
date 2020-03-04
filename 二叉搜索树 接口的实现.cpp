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
     ,data_(data)
  {}

  BSTNode<T>* pLeft_;
  BSTNode<T>* pRight_;
  T data_;
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
private:

    PNode pNode_;
};
