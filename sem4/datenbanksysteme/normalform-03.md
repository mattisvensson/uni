---
Date: 13.04.2026
Slide: Datenbanksysteme - 03.pdf - p. 89
---

V = Verkäufer
K = Kunde
D = Datum
A = Artikel
L = Lieferadresse
P = Preis
H = Hersteller

Relation:
bestellung(V,K,D,A,H,L,P)

FD-Menge:
F = {
    {K} -> {V},
    {K,D} -> {L,A},
    {D,A,H} -> {P},
    {A} -> {H},
    {L} -> {K}
}

Kandidatenschlüssel: 
    1. KD -> LA -> H -> P
    2. LD -> KD -> ...

1. Normalform
    - Ist gegeben (nehmen wir an)

2. Normalform