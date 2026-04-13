---
Date: 13.04.2026
Slide: Datenbanksysteme - 03.pdf - p. 54
---

Klasse: {[<ins>kID: string</ins>, raum: string]}

ist_in: {[kID: string, <ins>sID: string</ins>]}

Schueler: {[<ins>sID: string</ins>, name: string, adresse: string, geburtsdatum: date]}



Unterrichtsfach: {[<ins>fID: string</ins>, <ins>schuljahr: string</ins>, title: string, WS: string]}

unterrichten: {[fID: string, lID: string]} 

Lehrer: {[<ins>lID: string</ins>, name: string, adresse: string, geburtsdatum: date]}

ist_KL: {[lID: string, <ins>kID: string</ins>]}
