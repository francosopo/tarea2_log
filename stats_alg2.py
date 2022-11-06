import pandas as pd
import matplotlib.pyplot as plt


filename = "alg2_aristas__tiempo_segundos_v2.csv"

df = pd.read_csv(filename, sep=',')
df.plot(
    x='naristas',
    y='tiempo_s',
    xlabel="Número de aristas",
    ylabel="Tiempo transcurrido [s]",
    title="Listas de adyacencia",
    legend="Tiempo promedio",
    logx=True,
    logy=True,
    marker='o')
plt.show()