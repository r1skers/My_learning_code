from sympy import symbols, Eq, solve, Rational

I1, v2, I3, I4,  E1, r1, r2, r3, r4,I = symbols('I1 v2 I3 I4  E1 r1 r2 r3 r4 I')

eq1 = Eq(I, I4 +I3)
eq2 = Eq(I4*r4, (I3*r3)+v2)
eq3 = Eq(v2/r2 , (I1*r1) + (I3*r3))
eq4 = Eq(E1,(I1*r1)+v2)


solution = solve([eq1, eq2, eq3, eq4], [I1, v2, I3, I4, I], dict=True)

print(solution)