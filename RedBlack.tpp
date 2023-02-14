namespace RB {
    // NODE DEFINITIONS
    template <typename T> Node<T>::Node(T const arg)
    {
        val = arg;
        isRed = true;

        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }


    // RED BLACK DEFINITIONS
    template <typename T> RedBlack<T>::RedBlack()
    {
        root = nullptr;
    }

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
                    // DO SOMETHING OTHER THAN COUT
                    //std::cout << "EXCEPTION" << std::endl;
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
                // DO SOMETHING OTHER THAN COUT
                //std::cout << "EXCEPTION" << std::endl;
            }

            node_to_insert->parent = prior_ptr;
        }

        insert_balance(node_to_insert);

    }

    template <typename T> void RedBlack<T>::insert_balance(Node<T>* inserted_node)
    {
        // TODO
    }

    template <typename T> void RedBlack<T>::rotate_right(Node<T>* x)
    {
        // TODO
    }

    template <typename T> void RedBlack<T>::rotate_left(Node<T>* x)
    {
        // TODO
    }

    // Recursive function risks stack overflow, but I think that'd be pretty hard to do with an RedBlack tree.
    template <typename T> void RedBlack<T>::recursive_destroy(Node<T>* node)
    {
        if (node)
        {
            recursive_destroy(node->left);
            recursive_destroy(node->right);
            delete node;
        }
    }

    template <typename T> void RedBlack<T>::print_tree(const std::string& prefix, const Node<T>* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value and color of the node
            std::cout << node->val << (node->isRed ? "/R" : "/B") << std::endl;

            // enter the next tree level - left and right branch
            print_tree( prefix + (isLeft ? "│   " : "    "), node->left, true);
            print_tree( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

    template <typename T> void RedBlack<T>::print_tree(const Node<T>* node)
    {
        print_tree("", node, false);
    }
} // Namespace RedBlack