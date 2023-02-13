namespace RB {
    // NODE DEFINITIONS
    template <typename T> Node<T>::Node(T const arg)
    {
        this->val = arg;
        this->isRed = true;

        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }


    // RED BLACK DEFINITIONS
    template <typename T> RedBlack<T>::RedBlack()
    {
        this-> root = nullptr;
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

        // TO DO
        balance_tree(node_to_insert);

    }

    template <typename T> void RedBlack<T>::balance_tree(Node<T>* inserted_node)
    {
        // TO DO
    }
} // Namespace RedBlack