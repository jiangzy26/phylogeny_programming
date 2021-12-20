#!/bin/python3

"""
Assume we have a very simple case
we just want to calculate the probability of a give tree 
(three samples with one internal node)

And Assume the the branch length is:
Sample1: t1
Sample2: t2
Sample3: t3

The tree topology is (S1:t1, S2:t2, S3:t3)


the probability which under JC69 model

λ: branch length
Different state is 1/4*(1-e^(-λ))
And same state is 1/4+3/4e^(-λ)

"""
import math


def get_Pr_under_JC69(t1,t2,t3,S1,S2,S3):

	#the initial Probability is 0 
	Pr = 0
	internal_node_stat = ['A', 'T','C','G']

	for stat in internal_node_stat:
		#For each aligned nucleotide
		for number in range(0,len(S1)):
			if stat == S1[number]:
				Pr = Pr + math.log( (1/4 - 1/4 * math.e**(-t1)), 10)#the base is 10
			else:
				Pr = Pr + math.log( (1/4 + 3/4 * math.e**(-t1)), 10)

			if stat == S2[number]:
				Pr = Pr + math.log( (1/4 - 1/4 * math.e**(-t2)), 10)
			else:
				Pr = Pr + math.log( (1/4 + 3/4 * math.e**(-t2)), 10)

			if stat == S3[number]:
				Pr = Pr + math.log( (1/4 - 1/4 * math.e**(-t3)), 10)
			else:
				Pr = Pr + math.log( (1/4 + 3/4 * math.e**(-t3)), 10)

	return Pr


if __name__ == "__main__":

	#define the sequence
	S1 = "ATGG"
	S2 = "AAGG"
	S3 = "TACG"

	#define the branch length of each sample, which correspond to each sample
	t1 = 1
	t2 = 1
	t3 = 1

	Pr = get_Pr_under_JC69(t1,t2,t3,S1,S2,S3)
	print("The Log probability is %s " %Pr)
