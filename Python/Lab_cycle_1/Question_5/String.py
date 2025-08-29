{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "String.ipynb",
      "provenance": [],
      "collapsed_sections": [],
      "authorship_tag": "ABX9TyPJ4Dxi+hN1fGs1b4hI5U43",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/sandralayas/library/blob/Python-practice-problems/String.ipynb\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": 3,
      "metadata": {
        "id": "IrnzEcFrOYm4",
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "outputId": "02081988-854a-444e-8e8f-b976774946d4"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Enter the string :abacdc\n",
            "\n",
            " All the sub strings\n",
            "abacdc bacdc acdc cdc dc c abacd bacd acd cd d abac bac ac c aba ba a ab b a \n",
            "\n",
            "Enter the length : 3\n",
            "\n",
            " Substrings of length 3\n",
            "cdc acd bac aba \n",
            "\n",
            " Substrings of length 3 which only have distinct character\n",
            "acd bac \n",
            "\n",
            " Palindromes :\n",
            "cdc c d c aba a b a "
          ]
        }
      ],
      "source": [
        "# Question 5 ; String\n",
        "\n",
        "def get_substring(word):\n",
        "  list_of_strings=[]\n",
        "  for i in range(len(word)):\n",
        "    for j in range(len(word)):\n",
        "      list_of_strings.append(word[j:])  # Appends the sliced string to list_of_strings\n",
        "    word=word[:len(word)-1]   # Remove the last character from the word  \n",
        "  return list_of_strings  # Returns the list\n",
        "\n",
        "def print_palindrome(word):\n",
        "  for i in get_substring(word):  # Takes each substring\n",
        "    if i==i[::-1]:print(i,end=' ')   # Checks if its palindrome\n",
        "\n",
        "def word_length(word,length):\n",
        "  for i in get_substring(word):  # Takes each substring\n",
        "    if len(i)==length:print(i,end=' ')   # Checks if its of the given length\n",
        "\n",
        "def print_length_distinct(word,length):\n",
        "  for i in get_substring(word):  # Takes each substring\n",
        "    if len(i)==length:   # Checks if its of the given length\n",
        "      if len(set(i))==len(i):print(i,end=' ')   # Checks if its distinct\n",
        "\n",
        "\n",
        "word=input( 'Enter the string :')\n",
        "\n",
        "print('\\n All the sub strings')\n",
        "\n",
        "for i in get_substring(word):print(i,end=' ')\n",
        "\n",
        "length=int(input('\\n\\nEnter the length : '))\n",
        "\n",
        "print('\\n Substrings of length',length) \n",
        "word_length(word,length)\n",
        "print('\\n\\n Substrings of length',length,'which only have distinct character') \n",
        "print_length_distinct(word,length)\n",
        "print('\\n\\n Palindromes :')\n",
        "print_palindrome(word)"
      ]
    }
  ]
}
