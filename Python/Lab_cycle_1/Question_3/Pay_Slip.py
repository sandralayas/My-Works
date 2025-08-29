{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Pay_Slip.ipynb",
      "provenance": [],
      "collapsed_sections": [],
      "authorship_tag": "ABX9TyNmP8iZejHh3nLaQ2iVPsn1",
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
        "<a href=\"https://colab.research.google.com/github/sandralayas/library/blob/Python-practice-problems/Pay_Slip.ipynb\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": 2,
      "metadata": {
        "id": "pIO9_ypoNwmF",
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "outputId": "ac0e956d-fc3a-443f-b8f3-df944e30f195"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Enter the employee name : Rohit Manohar\n",
            "Enter the code : 342765\n",
            "Enter the basic pay : 30400\n",
            "\n",
            "Gross_salary :  41024.0\n",
            "\n",
            "Deduction :  6748.0\n",
            "\n",
            "Net salary : 34276.0\n"
          ]
        }
      ],
      "source": [
        "# Question 3 ; payslip\n",
        "\n",
        "def read_details():# Reads the details of the employees\n",
        "  a=(input('Enter the employee name : '))\n",
        "  b=int(input('Enter the code : '))\n",
        "  c=float(input('Enter the basic pay : '))\n",
        "  return a,b,c\n",
        "\n",
        "def gross_salary(salary):\n",
        "  if salary<10000:return salary*(1+0.05+0.025)+500 # salary<10000\n",
        "  elif salary>10000 and salary<30000:return salary*(1+0.075+0.05)+2500 # salary<30000\n",
        "  elif salary>30000 and salary<50000:return salary*(1+0.11+0.075)+5000 # salary<50000\n",
        "  else:return salary*(1+0.25+0.11)+7000 # Others\n",
        "\n",
        "def deduction(salary):\n",
        "  if salary<10000:return salary*0.08+20 # salary<10000\n",
        "  elif salary>10000 and salary<30000:return salary*0.08+60 # salary<30000\n",
        "  elif salary>30000 and salary<50000:return salary*(0.11+0.11)+60 # salary<50000\n",
        "  else:return salary*(0.12+0.2)+60 # Others\n",
        "\n",
        "name,code,salary=read_details()\n",
        "print('\\nGross_salary : ',gross_salary(salary))\n",
        "print('\\nDeduction : ',deduction(salary))\n",
        "print('\\nNet salary :',gross_salary(salary)-deduction(salary))"
      ]
    }
  ]
}
