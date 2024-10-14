#harga 1 butir dalam ratusan rupiah
merah=10
hijau=15
kuning=20

#input jumlah kelereng
m=int(input("jumlah kelereng merah :"))
h=int(input("jumlah kelereng hijau :"))
k=int(input("jumlah kelereng kuning :"))

total_harga = (m * merah) + (h *  hijau) + (k * kuning)

print(f"Total yang harus dibayarkan : Rp.", total_harga,)
