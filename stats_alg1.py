import pandas as pd
import matplotlib.pyplot as plt

header= [
    "naristas",
    "time_elapsed"
]

filename = "alg1_aristas__tiempo_segundos_v2.csv"

df = pd.read_csv(filename, sep=',', names=header)
df.plot(
    x='naristas',
    y='time_elapsed',
    xlabel="Número de aristas",
    ylabel="Tiempo transcurrido [s]",
    title="Listas de adyacencia",
    legend="Tiempo promedio",
    logx=True,
    logy=True,
    marker='o')
plt.show()