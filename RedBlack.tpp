namespace RB {
    /****  NODE DEFINITIONS  ****/
    // Constructor
    template <typename T> Node<T>::Node(T const arg)
    {
        val = arg;
        isRed = true;

        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }


    /****  RED BLACK DEFINITIONS  ****/
    // Constructor
    template <typename T> RedBlack<T>::RedBlack()
    {
        root = nullptr;
    }

    // Destructor
    template <typename T> RedBlack<T>::~RedBlack()
    {
        recursive_destroy(root);
    }

    template <typename T> Node<T>* RedBlack<T>::search(T desired_val, Node<T>* start)
    {
        if (start == nullptr)
        {
            return nullptr;
        }
        else
        {
            // Node found
            if (start->val == desired_val)
            {
                return start;
            }
            // Recurse left side
            else if (start->val < desired_val)
            {
                return search(desired_val, start->right);
            }
            // Recurse right side
            else if (start->val > desired_val)
            {
                return search(desired_val, start->left);
            }
        }
        return nullptr;
    }

    template <typename T> Node<T>* RedBlack<T>::search(T desired_val)
    {
        return search(desired_val, root);
    }

    template <typename T> void RedBlack<T>::insert(T value)
    {
        // Instantiates a node object to be pushed
        Node<T> *node_to_insert = new Node<T> (value);

        // Empty tree (root == nullptr)
        if (root == nullptr)
        {
            root = node_to_insert;
            root->isRed = false;
        }

        else
        {
            Node<T> *tree_ptr, *prior_ptr;
            tree_ptr = root;

            prior_ptr = tree_ptr;

            while (tree_ptr != nullptr)
            {
                prior_ptr = tree_ptr;
                if (value < tree_ptr->val)
                {
                    tree_ptr = tree_ptr->left;
                }
                else if (value > tree_ptr->val)
                {
                    tree_ptr = tree_ptr->right;
                }
                else
                {
                    // This control path should never be executed...
                    //throw std::logic_error;
                }
            }

            // Once arrived at the bottom layer of the tree, determine which side to insert on...
            if (value < prior_ptr->val)
            {
                prior_ptr->left = node_to_insert;
            }
            else if (value > prior_ptr->val)
            {
                prior_ptr->right = node_to_insert;
            }
            else
            {
                // This control path should never be executed...
                    //throw std::logic_error;
            }

            node_to_insert->parent = prior_ptr;
        }

        // Maintain root = black invariant.
        root->isRed = false;

    }

    template <typename T> Node<T>* RedBlack<T>::rotate_right(Node<T>* h)
    {
        assert(h->left->isRed);

        Node<T>* x = h->left;
        h->left = x->right;
        x->right = h;
        x->isRed = h->isRed;
        h->isRed = true;

        return x;
    }

    template <typename T> Node<T>* RedBlack<T>::rotate_left(Node<T>* h)
    {
        assert(h->right->isRed);

        Node<T>* x = h->right;
        h->right = x->left;
        x->left = h;
        x->isRed = h->isRed;
        h->isRed = true;
    }

    template <typename T> void RedBlack<T>::flip_colors(Node<T>* h)
    {
        assert(!h->isRed);
        assert(h->left->isRed);
        assert(h->right->isRed);

        h->isRed = true;
        h->left->isRed = false;
        h->right->isRed = false;
    }

    // Recursive function risks stack overflow, but I think that'd be pretty hard to do with a (balanced) RedBlack tree.
    template <typename T> void RedBlack<T>::recursive_destroy(Node<T>* node)
    {
        if (node)
        {
            recursive_destroy(node->left);
            recursive_destroy(node->right);
            delete node;
        }
    }

    // Recursive function risks stack overflow...
    template <typename T> void RedBlack<T>::print_tree(const std::string& prefix, const Node<T>* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value and color of the node
            std::cout << node->val << (node->isRed ? "/R" : "/B") << std::endl;

            // Recursive calls on left and right child nodes...
            print_tree( prefix + (isLeft ? "│   " : "    "), node->left, true);
            print_tree( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

    template <typename T> void RedBlack<T>::print_tree(const Node<T>* node)
    {
        print_tree("", node, false);
    }


} // Namespace RedBlack