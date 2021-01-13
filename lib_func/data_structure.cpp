#include "data_structure.h"

Link::Link()
{
  cout << "initialise\n";
  head = new Node;
  head->next = NULL;
}

Link::~Link()
{
  while (head)
  {
    Node *temp;
    temp = head->next;
    delete head;
    head = temp;
  }
}

bool Link::insert(const int &data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->next = head->next;
  head->next = temp;
  return true;
}
bool Link::insert(const uint &pos, const int &data)
{
  if (pos < 0)
    return false;
  Node *temp = head;
  if (pos == 0)
  {
    insert(data);
  }
  else
  {
    for (uint i = 0; i < pos; i++)
    {
      temp = temp->next;
    }
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
  }
  return true;
}
void Link::push_back(const int &data)
{
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  Node *new_node = new Node;
  new_node->next = NULL;
  new_node->data = data;
  temp->next = new_node;
  // head = temp;
}
void Link::erase(const uint &pos)
{
  Node *temp = head;
  int p = pos;
  while (p)
  {
    p--;
    temp = temp->next;
  }
  Node *delete_node = temp->next;
  temp->next = temp->next->next;
  delete delete_node;
}
void Link::erase(const uint &beg, const uint &end)
{
  Node *temp = head;
  int b = beg;
  while (b)
  {
    b--;
    temp = temp->next;
  }
  uint times = end - beg;
  while (times--)
  {
    Node *delete_node = temp->next;
    temp->next = delete_node->next;
    delete delete_node;
  }
}
void Link::remove(const int &data)
{
  Node *delete_node;
  Node *temp = head;
  // 检查是否已经检测到链表尾部了
  while (temp->next && temp->next->data != data)
  {
    temp = temp->next;
  }
  // 如果还没到达链表尾部，则意味着找到了指定节点
  if (temp->next)
  {
    delete_node = temp->next;
    temp->next = delete_node->next;
    delete delete_node;
  }
}

uint32_t Link::size()
{
  Node *temp = head;
  uint32_t n = 0;
  while (temp->next)
  {
    n++;
    temp = temp->next;
  }
  return n;
}

int Link::operator[](const uint &pos)
{
  Node *temp = head;
  uint32_t p = pos;
  if (pos < 0 || pos >= size())
  {
    cout << "invalid postion\n";
    return -1;
  }
  while (p--)
  {
    temp = temp->next;
  }
  return temp->next->data;
}
int Link::front()
{
  if (head->next)
    return head->next->data;
  else
  {
    return -1;
  }
}
int Link::back()
{
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  return temp->data;
}
int Link::pop_back()
{
  if (!size())
  {
    return -999999;
  }
  Node *temp;
  Node *delete_node = head;
  while (delete_node->next)
  {
    temp = delete_node;
    delete_node = delete_node->next;
  }
  int data = delete_node->data;
  temp->next = NULL;
  delete delete_node;
  return data;
}
int Link::pop_front()
{
  if (head->next)
  {
    Node *delete_node = head->next;
    head->next = head->next->next;
    int data = delete_node->data;
    delete delete_node;
    return data;
  }
  return -1; //返回失败　是一个空的链表
}
void Link::print()
{
  cout << "Printing all data from head to tail in this link\n";
  Node *temp = head;
  while (temp->next)
  {
    cout << temp->next->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void Link::reverse()
{
  Node *p = head->next;
  Node *q, *m;
  if (p && p->next)
  {
    q = p->next;
  }
  else
  {
    return;
  }
  if (q && q->next)
  {
    m = q->next;
  }
  else
  {
    m = NULL;
  }

  p->next = NULL;
  while (m)
  {
    q->next = p;
    p = q;
    q = m;
    m = m->next;
  }
  q->next = p;
  head->next = q;
}