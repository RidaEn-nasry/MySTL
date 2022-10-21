/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:32:49 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 16:13:25 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.hpp>

// ft::AVLNode<int> *create_dummy_tree()
// {
    // ft::AVLNode<int>* root = new ft::AVLNode<int>(15);
    // ft::AVLNode<int>* node1 = new ft::AVLNode<int>(11);
    // root->setLeft(node1);
    // node1->setParent(root);
    // ft::AVLNode<int>* node2 = new ft::AVLNode<int>(21);
    // root->setRight(node2);
    // node2->setParent(root);
    // ft::AVLNode<int>* node3 = new ft::AVLNode<int>(10);
    // node1->setLeft(node3);
    // node3->setParent(node1);
    // ft::AVLNode<int>* node4 = new ft::AVLNode<int>(12);
    // node1->setRight(node4);
    // node4->setParent(node1);
    // ft::AVLNode<int>* node7 = new ft::AVLNode<int>(13);
    // node4->setRight(node7);
    // node7->setParent(node4);
    // ft::AVLNode<int>* node5 = new ft::AVLNode<int>(20);
    // node2->setLeft(node5);
    // node5->setParent(node2);
    // ft::AVLNode<int>* node6 = new ft::AVLNode<int>(22);
    // node2->setRight(node6);
    // node6->setParent(node2);
//     return root;
// }

void ft_avlnode_tests_suite()
{

    /****************************************************************************/
    /*                              Member types                                */
    /****************************************************************************/

    {
        std::string test_name("ft::AVLNode Member types tests ");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::value_type).name(), typeid(ft::pair<int, int>).name(), test_name, "`value_type` member type is not the same as the template parameter");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::pointer).name(), typeid(ft::pair<int, int> *).name(), test_name, "`pointer` member type is not the same as the template parameter");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::reference).name(), typeid(ft::pair<int, int> &).name(), test_name, "`reference` member type is not the same as the template parameter");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::const_pointer).name(), typeid(ft::pair<int, int> const *).name(), test_name, "`const_pointer` member type is not the same as the template parameter");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::const_reference).name(), typeid(ft::pair<int, int> const &).name(), test_name, "`const_reference` member type is not the same as the template parameter");
        // REQUIRE_EQ(typeid(ft::AVLNode<ft::pair<int, int> >::key_compare).name(), typeid(ft::less<ft::pair<int, int> >).name(), test_name, "`key_compare` member type is not the same as the template parameter");
        INFO_OK(test_name);
    }

    /****************************************************************************/
    /*                              Constructors                                */
    /****************************************************************************/

    {
        std::string test_name("ft::AVLNode Constructors tests ");
        // ft::AVLNode<ft::pair<int, int> > node;
        // REQUIRE_EQ(node.height(), 1, test_name, "`height` should be 1 when node is default constructed. instead it is " << node.height());
        // REQUIRE_EQ(node.parent(), NULL, test_name, "`parent` should be NULL when node is default constructed");
        // REQUIRE_EQ(node.left(), NULL, test_name, "`left` should be NULL when node is default constructed");
        // REQUIRE_EQ(node.right(), NULL, test_name, "`right` should be NULL when node is default constructed");

        // ft::AVLNode<ft::pair<int, std::string> > node2(ft::pair<int, std::string>(42, "42"), NULL);
        // REQUIRE_EQ(node2.height(), 1, test_name, "`height` should be 1 when node is constructed with a value and a parent. instead it is " << node2.height());
        // REQUIRE_EQ(node2.parent(), NULL, test_name, "`parent` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node2.left(), NULL, test_name, "`left` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node2.right(), NULL, test_name, "`right` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node2.data().first, 42, test_name, "`data().first` should be `data.first` when node is constructed with a value and a parent");
        // REQUIRE_EQ(node2.data().second, "42", test_name, "`data().second` should be `data.second` when node is constructed with a value and a parent");
        INFO_OK(test_name);
    }

    /* ************************************************************************** */
    /*                                  Getters                                   */
    /* ************************************************************************** */

    {
        std::string test_name("ft::AVLNode Getters tests ");
        // ft::AVLNode<ft::pair<ft::stack<int>, ft::vector<int> > > node(ft::pair<ft::stack<int>, ft::vector<int> >(ft::stack<int>(), ft::vector<int>()), NULL);
        // REQUIRE_EQ(node.height(), 1, test_name, "`height` should be 1 when node is constructed with a value and a parent. instead it is " << node.height());
        // REQUIRE_EQ(node.parent(), NULL, test_name, "`parent` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node.left(), NULL, test_name, "`left` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node.right(), NULL, test_name, "`right` should be NULL when node is constructed with a value and a parent");
        // REQUIRE_EQ(node.data().first.size(), 0, test_name, "`data().first` should be `data.first` when node is constructed with a value and a parent");
        // REQUIRE_EQ(node.data().second.size(), 0, test_name, "`data().second` should be `data.second` when node is constructed with a value and a parent");
        // REQUIRE_EQ(typeid(node.data_ptr()).name(), typeid(ft::pair<ft::stack<int>, ft::vector<int> > *).name(), test_name, "`data_ptr` should return a pointer to the data");
        // REQUIRE_EQ(node.balance(), 0, test_name, "`balance` should return 0 when the node is balanced");
        INFO_OK(test_name);
    }

    /* ************************************************************************** */
    /*                                  Setters                                   */
    /* ************************************************************************** */
    {
        std::string test_name("ft::AVLNode Setters tests ");
        //     ft::AVLNode<ft::pair<int, int> >* node = new ft::AVLNode<ft::pair<int, int> >();
        //     ft::pair<int, int> data(42, 42);
        //     node->setData(data);
        //     REQUIRE_EQ(typeid(node->data()).name(), typeid(ft::pair<int, int>).name(), test_name, "`data` should return a reference to the data");
        //     ft::AVLNode<ft::pair<int, int> > *node2 = new ft::AVLNode<ft::pair<int, int> >();
        //     ft::pair<int, int> data2(42, 42);
        //     node2->setData(data2);
        //     node->setLeft(node2);
        //     node2->setParent(node);
        //     REQUIRE_EQ(typeid(node->left()).name(), typeid(ft::AVLNode<ft::pair<int, int> > *).name(), test_name, "`left` should return a pointer to the left child");
        //     REQUIRE_EQ(typeid(node->parent()).name(), typeid(ft::AVLNode<ft::pair<int, int> > *).name(), test_name, "`parent` should return a pointer to the parent");
        //     ft::AVLNode<ft::pair<int, int> > *node3 = new ft::AVLNode<ft::pair<int, int> >();
        //     ft::pair<int, int> data3(42, 42);
        //     node3->setData(data3);
        //     node->setRight(node3);
        //     node3->setParent(node);
        //     REQUIRE_EQ(typeid(node->right()).name(), typeid(ft::AVLNode<ft::pair<int, int> > *).name(), test_name, "`right` should return a pointer to the right child");
        //     REQUIRE_EQ(typeid(node->parent()).name(), typeid(ft::AVLNode<ft::pair<int, int> > *).name(), test_name, "`parent` should return a pointer to the parent");
        INFO_OK(test_name);
    }
    /* ************************************************************************** */
    /*                            non-member overload                             */
    /* ************************************************************************** */
    {
        std::string test_name("ft::AVLNode non-member overloads tests ");
        //     ft::AVLNode<ft::pair<int, int> > *node = new ft::AVLNode<ft::pair<int, int> >();
        //     ft::pair<int, int> data(42, 42);
        //     node->setData(data);
        //     ft::AVLNode<ft::pair<int, int> > *node2 = new ft::AVLNode<ft::pair<int, int> >;
        //     ft::pair<int, int> data2(43, 43);
        //     node2->setData(data2);
        //     node->setLeft(node2);
        //     node2->setParent(node);
        //     ft::AVLNode<ft::pair<int, int> > *node3 = new ft::AVLNode<ft::pair<int, int> >;
        //     ft::pair<int, int> data3(42, 42);
        //     node3->setData(data3);
        //     node->setRight(node3);
        //     node3->setParent(node);
        //     REQUIRE_EQ(node->balance(), 0, test_name, "`balance` should return 0 when the tree is balanced");
        //     node->setRight(NULL);
        //     REQUIRE_EQ(node->balance(), 1, test_name, "`balance` should return 1 when the tree is unbalanced");
        //     node->setRight(node3);

        //     REQUIRE_NEQ(node, node2, test_name, "`operator!=` should return true when nodes are different");
        //     REQUIRE_LT(node, node2, test_name, "`operator<` should return true when the first node is smaller than the second");
        //     REQUIRE_GT(node2, node, test_name, "`operator>` should return true when the first node is bigger than the second");
        //     REQUIRE_GE(node2, node, test_name, "`operator>=` should return true when the first node is bigger than the second");
        //     REQUIRE_LE(node, node2, test_name, "`operator<=` should return true when the first node is smaller than the second");
        //     REQUIRE_EQ(node, node, test_name, "`operator==` should return true when nodes are equal");
        INFO_OK(test_name);
    }

    /* ************************************************************************** */
    /*                           next/prev operations                             */
    /* ************************************************************************** */

    {
        std::string test_name("ft::AVLNode next/prev operations tests ");
        // ft::AVLNode<int> *root = create_dummy_tree();
        // ft::AVLNode<int>* min = root->left()->left();
        // REQUIRE_EQ(min->next(), root->left(), test_name, "`next` should return the next node in the tree");
        // REQUIRE_EQ(root->prev(), root->left()->right()->right(), test_name, "`prev` should return the previous node in the tree as of Comparator");
        INFO_OK(test_name);
    }
}