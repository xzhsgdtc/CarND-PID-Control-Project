import pandas as pd
import sys
import matplotlib.pyplot as plt


df = pd.read_csv(sys.argv[1],names=['step','cte','error'])

print(df.head())


import plotly
import plotly.plotly as py
import plotly.graph_objs as go

# Create random data with numpy
import numpy as np

N = len(df)
random_x = np.linspace(0, 1, N)
random_y0 = df['cte']
random_y1 = df['error']

# Create traces
trace0 = go.Scatter(
    x = random_x,
    y = random_y0,
    mode = 'lines',
    name = 'cte'
)
trace1 = go.Scatter(
    x = random_x,
    y = random_y1,
    mode = 'lines',
    name = 'average error'
)

data = [trace0, trace1]

plotly.offline.plot(data, filename='{}'.format(sys.argv[1].split('.')[0]))

