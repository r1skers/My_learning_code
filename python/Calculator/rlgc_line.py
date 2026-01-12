import numpy as np

def tl_params(
    f_hz,
    R_per_km,
    L_mH_per_km,
    C_uF_per_km,
    G_per_km=0.0,
    polar=False,   # 是否输出极坐标（可选）
    Z=0,
    Y=0,
):
    """
    Transmission line parameters (per km).

    polar=False:
        return complex numbers directly (a + jb)

    polar=True:
        also return magnitude and phase (degree)
    """

    # omega = 2 * np.pi * f_hz

    # unit conversion
    # L = L_mH_per_km * 1e-3   # mH -> H
    # C = C_uF_per_km * 1e-6   # uF -> F

    # per-unit-length quantities
    # Z = R_per_km + 1j * omega * L
    # Y = G_per_km + 1j * omega * C

    Z0 = np.sqrt(Z / Y)
    gamma = np.sqrt(Z * Y)

    alpha = gamma.real
    beta  = gamma.imag

    result = {
        "Z (ohm/km)": Z,
        "Y (S/km)": Y,
        "Z0 (ohm)": Z0,
        "gamma (/km)": gamma,
        "alpha (Np/km)": alpha,
        "beta (rad/km)": beta,
    }

    if polar:
        result.update({
            "|Z0|": abs(Z0),
            "∠Z0 (deg)": np.degrees(np.angle(Z0)),
            "|gamma|": abs(gamma),
            "∠gamma (deg)": np.degrees(np.angle(gamma)),
        })

    return result


if __name__ == "__main__":
    # ===== problem 1 parameters =====
    # f = 50.0
    # R = 1.0          # ohm/km
    # L = 2        # mH/km
    # C = 300      # uF/km
    # G = 0.5
    Z = 0.144+0.936j  # ohm/km
    Y = 0.7274e-7j  # S/km
    # res = tl_params(f, R, L, C, G, polar=False)
    res = tl_params(0, 0, 0, 0, 0, polar=False, Z=Z, Y=Y)

    print("=== Transmission Line Parameters (rectangular form) ===")
    for k, v in res.items():
        print(f"{k:16s}: {v}")
