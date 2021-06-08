# Gradient-Descent-on-Iris-Fisher-s-Dataset
Training Iris/Fisher’s Data Set using Gradient Descent in C++.

In order to randomize the dataset, we wrote a separate c++ code, attached as “RandomizeDataset.cpp”. We first converted the given .xlsx file to .txt file and then fed it into this code. This generated a randomized .txt file called “randomized dataset.txt”. We then used this file in our main c++ code.
The reason for doing this is that if we simply randomized the dataset in our main code, then we would not be able to produce consistent results. At each run of the code, rand() would be seeded to a different time and hence, the dataset would be randomized in a different way. In order to be able to observe and report consistent results, we used the aforementioned method of randomizing the dataset.
The weight vector we used initially was:
W= [0.00001, 0.00001, 0.00002, 0.00003, 0.00001]
The training rate we used throughout the code is 0.001
The size of the dataset provided to us was 150.

Cost when using 75 entries of the dataset for training:

We used the first 50% of the dataset (i.e. 75 entries) to train the Perceptron. After reaching 1000 iterations, the cost was reduced to 1.978622.

Classifying, using the remaining 75 entries of the dataset:

We then tested the classifier using the remaining 50% (last 75 entries of the randomized dataset). The number of mismatches we found were 75. This is problematic because this means that 100% of the tests were mismatched. This shows us that, since we did not use the step function, a complete one to one correspondence was not made between yHat and y. This is perhaps because exact matches, down to each decimal place, are statistically extremely unlikely to happen. 
Rounding off yHat:
Then, we rounded off yHat according to the following scheme:
if yHat ≤ 1.5 → class = 1
if 1.5 < yHat≤2.5 → class = 2
if yHat > 2.5 → class = 3
After rounding off, the number of mismatches we encountered were only 3, which is a huge improvement from previous results. This shows the importance of a step/activation function.

Cost when using 100 entries of the dataset for training:

Next up, we repeated the above steps, now using 75% of the dataset for training, i.e. 100 entries. The final cost produced at the 1000th iteration was more than the cost produced when we were using 50% of the dataset for training.

Classifying the remaining 50 entries of the dataset:

Following a procedure similar to the above, we used the remaining 25% of the dataset (last 50 entries) to test the classifier. Similar to the above results, we found that the number of mismatches were 50, i.e. 100% of the tests were mismatched.
Rounding off yHat:
We then rounded off yHat using the same scheme highlighted above. After this, the number of mismatches were only 2, which is a much better result as compared with the one above.

Conclusion:

Our series of experiments showed that the cost we obtained by splitting the data at 75:75, was 1.978622, while the cost obtained at 100:50 was 2.528089. Without rounding off, in both scenarios, the number of mismatched tests were 100%. After rounding off, in the 75:75 case, there were 3 mismatches and in the 100:50 case, there were 2 mismatches. Overall, the cost did not decrease when we moved from the first scenario to the next but the number of mismatched tests did decrease slightly.

