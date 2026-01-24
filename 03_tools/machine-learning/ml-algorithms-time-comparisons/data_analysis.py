import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import seaborn as sns


df_cpp = pd.read_csv("run_data_cplusplus.csv")
df_py = pd.read_csv("run_data_python.csv")

df_comb = df_cpp.append(df_py, ignore_index=True)
df_comb_mean = df_comb.groupby(['source','epoch'])['time(ms)'].mean().reset_index()
print(df_comb_mean)
sns.scatterplot(data=df_comb_mean, x='epoch', y='time(ms)' , hue='source').set(title='Epochs v/s Execution Time (Scatter)')
sns.lmplot(data=df_comb_mean, x='epoch', y='time(ms)' , hue='source').set(title='Epoch v/s Execution Time (Line)')
#sns.boxplot(data=df_comb, x='epoch', y='time(ms)' , hue='source')
plt.show()