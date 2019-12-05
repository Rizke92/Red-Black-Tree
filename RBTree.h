#include <iostream> 
template<typename K, typename V>
class RBTree
{
	private:

	class btnode
	{
		public:
		K key;
		V value;
		btnode *left;
		btnode *right;
		size_t *color; 
		
		btnode(const K& k)
		{
			key = k;
			left = nullptr;
			right = nullptr;
			color = NULL;
		}
		btnode(const K& k, const V& v)
		{
			key = k;
			value = v;
			left = nullptr;
			right = nullptr;
			color = NULL; 
		
		}

		~btnode()
		{
			delete left;
			left = nullptr;
			delete right;
			right = nullptr;
		}

	};
	
	size_t red = 1;
	size_t black = 0;
	size_t *rd = &red;
	size_t *bl = &black;
	size_t _size;
	char const *rr = "Red";
	char const *bb = "Black";
	
	btnode * _data;

	public:

	RBTree()
	{
		_size = 0;
		_data = nullptr;
	}

	~RBTree()
	{
		clear();
	}

	const char *NodeColor(const K& key)const
	{
		btnode *p = _data;
		
		while(p != nullptr)
		{
			if(key == p->key)
			{
				if(p->color == bl)
					return bb;
				if(p->color == rd)
					return rr;
			}
			else if(key > p->key)
			{
				p = p->right;
			}
			else if(key < p->key)
			{
				p = p->left;
			}
		}
		const char *x = "Ivalid Key";
		return x;
	}
		
	bool empty() const
	{
		return _size == 0;
	}

	size_t size() const
	{
		return _size;
	}

	size_t count(const K& k) const
	{
		btnode *ptr = _data;
		while (ptr != nullptr)
		{
			if (ptr->key == k)
				return 1;
			if (ptr->key < k)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return 0;

	}

	bool contains(const K& k) const
	{
		return count(k) != 0;
	}

	void clear()
	{
		delete _data;
		_data = nullptr;
		_size = 0;
	}
	
	void insert(const K& k, const V& v)
	{
		if (_data == nullptr)
		{
			_data = new btnode(k, v);
			btnode *val = _data;
			val->color = &black;
			_size++;
		}
		else
		{
			btnode *ptr = _data;
			while (ptr != nullptr)
			{
				if (ptr->key == k)
					return;
				if (ptr->key < k)
				{
					// check right side
					if (ptr->right == nullptr)
					{
						// we found the leafnode
						btnode *node = new btnode(k, v);
						ptr->right = node;
						node->value = v;
						_size ++;
						if(ptr->color == bl)
						{
							node->color = rd;
							return;
						}
						else
						{
							node->color = &black;
						}
						return;
					}
					else
					{
						ptr = ptr->right;
					}
				}
				else
				{
					// check left side
					if (ptr->left == nullptr)
					{
						// we found the leafnode
						btnode *node = new btnode(k, v);
						ptr->left = node;
						node->value = v;
						_size ++;
						if(ptr->color == bl)
						{
							node->color = rd;
							return;
						}
						else
						{
							node->color = bl;
							return;
						}
					}
					else
					{
						ptr = ptr->left;
					}
				}
			}
		}
	}
//--- Bracket Operator ------------------------------------------------------------------
	V& operator[](const K& key)
	{
		if(_data == nullptr)
		{
			_data = new btnode (key);
			_size++;
			btnode *val = _data;
			return  val-> value;
		}
		
		btnode *map = _data;
		
		while(map != nullptr)
		{
			if(key == map->key)
			{
				return map->value;
			}
			else if(key > map->key) // go right
			{
				if(map->right == nullptr)
				{
					btnode *rightLeaf = new btnode(key);
					map->right = rightLeaf;
					_size++;
					return rightLeaf->value;
				}
				else
				{
					map = map->right;
				}
			}
			else if(key < map->key) // go left
			{
				if(map->left == nullptr)
				{
					btnode *leftLeaf = new btnode(key);
					map->left = leftLeaf;
					_size++;
					return leftLeaf->value;
				}
				else
				{
					map = map->left;
				}
			}
		}
	}
	
//--- At ----------------------------------------------------------
	V& at(const K& key)
	{
		btnode *att = _data;
		
		while(att != nullptr)
		{
			if(key == att->key)
			{
				return att->value;
			}
			else if(key > att->key)
			{
				att = att->right;
			}
			else if(key < att->key)
			{
				att = att->left;
			}
		}
		if(att == nullptr)
			throw std::out_of_range ("Out of Range");
	}
	const V& at(const K& key)const 
	{
		btnode *att = _data;
		
		while(att != nullptr)
		{
			if(key == att->key)
			{
				return att->value;
			}
			else if(key > att->key)
			{
				att = att->right;
			}
			else if(key < att->key)
			{
				att = att->left;
			}
		}
		if(att == nullptr)
			throw std::out_of_range ("Out of Range");
	}
};