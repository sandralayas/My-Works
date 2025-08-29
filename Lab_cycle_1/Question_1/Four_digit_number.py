{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Four_digit_number.ipynb",
      "provenance": [],
      "authorship_tag": "ABX9TyNdrvlCCW4t464O1ZNy1Cqs",
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
        "<a href=\"https://colab.research.google.com/github/sandralayas/library/blob/Python-practice-problems/Four_digit_number.ipynb\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "id": "OdkHPt_C2EI1"
      },
      "outputs": [],
      "source": [
        "# Question one ; Four digit number\n",
        "\n",
        "number=input('Enter the four digit number : ')\n",
        "\n",
        "\n",
        "sum=int(number[0])+int(number[1])+int(number[2])+int(number[3])# Summing up the digits\n",
        "\n",
        "print(number[0],'+',number[1],'+',number[2],'+',number[3],'=',sum)\n",
        "print(number[::-1])# Prints the reversed number\n",
        "\n",
        "Opro=int(number[0])*int(number[2])# Product of the odd position\n",
        "Epro=int(number[1])*int(number[3])# Product of the even position\n",
        "\n",
        "print(number[0],'*',number[2],'-',number[1],'*',number[3],'=',Opro-Epro)# Prints the diffrence of products"
      ]
    }
  ]
}
