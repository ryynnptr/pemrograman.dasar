angka_pertama = int(input("masukkan angka pertama :"))
angka_kedua = int(input("Masukkan angka kedua:"))
operator=input("MAsukkan operasi aritmatika (+,  -, *, /):")


if operator == "+":
    hasil = angka_pertama + angka_kedua
elif operator == "-":
    hasil = angka_pertama - angka_kedua
elif operator == "*":
    hasil = angka_pertama * angka_kedua
elif operator == "/":
    hasil = angka_pertama / angka_kedua
    if angka_kedua == 0:
        hasil = "tidak dapat dibagi dengan nol :"
    else:
        hasil = angka_pertama // angka_kedua
elif operator == "%":
    if angka_kedua == 0:
        hasil = "tidak dapat dibagi dengan nol :"
    else:
        hasil = angka_pertama % angka_kedua
else:
    hasil="operator tidak valid"

    print(f"{angka_pertama} {operator} {angka_kedua} = {hasil}")


