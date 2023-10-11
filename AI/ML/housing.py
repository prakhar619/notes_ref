import numpy as np
def gradient_descent(x_data,y_label, alpha):
    m = np.size(y_label)
    temp_feature = np.zeros(np.size(x_data[0])) #no of features
    new_temp_feature = np.zeros(np.size(x_data[0]))
    print("No of features",len(temp_feature))
    print("No of training example", m)

    
    J = 1
    jth_function = 0
    while(J > 0.001):  #no of training examplex          
        for jth_feature in range(0,np.size(temp_feature)):  #no of features
            print("Jth Feature:", jth_feature)
            for mth_training_exm in range(0,m):
                jth_function += (np.dot(temp_feature,x_data[mth_training_exm]) - y_label[mth_training_exm])*x_data[mth_training_exm][jth_feature]
                print("Mth Training example",mth_training_exm)
            new_temp_feature[jth_feature] = temp_feature[jth_feature] - alpha*(1/m)*jth_function
        temp_feature = new_temp_feature
        for mth_training_cost in range(0,m):
            J = (1/(2*m))* (np.dot(temp_feature,x_data[mth_training_cost]) - y_label[mth_training_cost])
            print("Value of J",J)
    return temp_feature
        
import csv
fields = []
rows = []#lists of list

with open("./housing.csv", 'r') as csvfile:
    # creating a csv reader object
    csvreader = csv.reader(csvfile)
     
    # extracting field names through first row
    fields = next(csvreader)
 
    # extracting each data row one by one
    for row in csvreader:
    	for item in row:
    		row
        rows.append(row)

col = len(rows[0])
ro = len(rows)
x_data = [[]*col]*ro
y_label = []
i = 0
for eachrow in rows:
    for eachitem in eachrow[:8]:
        if(eachitem == ''):
            x_data[i].append(0)
        else:
            x_data[i].append(float(eachitem))
    y_label.append(float(eachrow[8]))
    i+=1

coffe_value = gradient_descent( x_data[:100],y_label[:100],0.01)
print(coffe_value)
