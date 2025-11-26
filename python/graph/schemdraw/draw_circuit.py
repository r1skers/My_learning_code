import schemdraw
import schemdraw.elements as elm

# 开启手绘风格 (XKCD)，如果你想要严谨的直线，把下面这行注释掉即可
# schemdraw.theme('xkcd') 

with schemdraw.Drawing(file='rlc_switch.svg') as d:
    
    # 1. 电源：使用 \n 换行，同时显示名称和电压
    d += (source := elm.SourceSin().up().label('$V_{in}$\n$10V$'))

    # 2. 【新增】开关：放在电源后面
    # 默认是断开的。如果想画闭合的，可以加 action='close' 参数
    d += elm.Switch().right().label('S1')

    # 3. 电阻：显示 100 欧姆
    d += elm.Resistor().right().label('$R$\n$100\Omega$')

    # 4. 电感：显示 10 milli-Henry
    d += elm.Inductor().right().label('$L$\n$10mH$')

    # 5. 电容：显示 47 micro-Farad (注意 \mu 的写法)
    d += elm.Capacitor().down().label('$C$\n$47\mu F$')

    # 6. 闭合回路：自动连回电源起点
    d += elm.Line().left().to(source.start)

    # 接地
    d += elm.Ground().at(source.start)

print("电路图生成完毕：rlc_switch.svg")