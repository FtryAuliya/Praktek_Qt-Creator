-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 02, 2024 at 01:33 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fitriyaauliya_2210010620`
--

-- --------------------------------------------------------

--
-- Table structure for table `barang`
--

CREATE TABLE `barang` (
  `kode_barang` int(25) NOT NULL,
  `nama_barang` varchar(50) NOT NULL,
  `jenis_barang` varchar(25) NOT NULL,
  `jml_barang` varchar(25) NOT NULL,
  `berat_barang` varchar(25) NOT NULL,
  `harga_barang` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `barang`
--

INSERT INTO `barang` (`kode_barang`, `nama_barang`, `jenis_barang`, `jml_barang`, `berat_barang`, `harga_barang`) VALUES
(100100, 'Laptop', 'Elektronik', '1', '45', '5500000'),
(100200, 'Spare Part', 'Otomotif', '2', '56', '230000');

-- --------------------------------------------------------

--
-- Table structure for table `kurir`
--

CREATE TABLE `kurir` (
  `id_kurir` int(25) NOT NULL,
  `nama_kurir` varchar(50) NOT NULL,
  `telp_kurir` varchar(12) NOT NULL,
  `wilayah` varchar(50) NOT NULL,
  `alamat_kurir` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `kurir`
--

INSERT INTO `kurir` (`id_kurir`, `nama_kurir`, `telp_kurir`, `wilayah`, `alamat_kurir`) VALUES
(22100, 'Cipung', '082389765646', 'Banjarmasin Utara', 'Jl. Sungai Andai'),
(22300, 'Rayyanza', '089967235647', 'Banjarmasin Tengah', 'Handil Bakti');

-- --------------------------------------------------------

--
-- Table structure for table `pegawai`
--

CREATE TABLE `pegawai` (
  `id_pegawai` int(25) NOT NULL,
  `nama_pegawai` varchar(50) NOT NULL,
  `alamat_pegawai` varchar(50) NOT NULL,
  `telp_pegawai` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pegawai`
--

INSERT INTO `pegawai` (`id_pegawai`, `nama_pegawai`, `alamat_pegawai`, `telp_pegawai`) VALUES
(300333, 'Ali', 'Guntung Paikat', '083817224314');

-- --------------------------------------------------------

--
-- Table structure for table `pelanggan`
--

CREATE TABLE `pelanggan` (
  `id_pelanggan` int(25) NOT NULL,
  `alamat_pelanggan` varchar(50) NOT NULL,
  `telp_pelanggan` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pelanggan`
--

INSERT INTO `pelanggan` (`id_pelanggan`, `alamat_pelanggan`, `telp_pelanggan`) VALUES
(55100, 'Sungai Tabuk', '081234562378');

-- --------------------------------------------------------

--
-- Table structure for table `pengiriman`
--

CREATE TABLE `pengiriman` (
  `no_resi` int(25) NOT NULL,
  `kode_barang` int(25) NOT NULL,
  `tgl_pengiriman` date NOT NULL,
  `id_pegawai` int(25) NOT NULL,
  `id_pelanggan` int(25) NOT NULL,
  `tgl_diterima` date NOT NULL,
  `nama_penerima` varchar(50) NOT NULL,
  `alamat_penerima` varchar(50) NOT NULL,
  `telp_penerima` varchar(12) NOT NULL,
  `id_tarif` int(25) NOT NULL,
  `biaya_asuransi` varchar(25) NOT NULL,
  `biaya_packing` varchar(25) NOT NULL,
  `berat_barang` varchar(25) NOT NULL,
  `total_biaya` int(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pengiriman`
--

INSERT INTO `pengiriman` (`no_resi`, `kode_barang`, `tgl_pengiriman`, `id_pegawai`, `id_pelanggan`, `tgl_diterima`, `nama_penerima`, `alamat_penerima`, `telp_penerima`, `id_tarif`, `biaya_asuransi`, `biaya_packing`, `berat_barang`, `total_biaya`) VALUES
(300300, 22200, '2025-06-05', 995000, 996000, '2025-06-08', 'Fitriya', 'Turki', '085645676677', 997000, '34000', '45000', '12', 79000);

-- --------------------------------------------------------

--
-- Table structure for table `tarif`
--

CREATE TABLE `tarif` (
  `id_tarif` int(25) NOT NULL,
  `asal` varchar(50) NOT NULL,
  `tujuan` varchar(50) NOT NULL,
  `biaya_tarif` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tarif`
--

INSERT INTO `tarif` (`id_tarif`, `asal`, `tujuan`, `biaya_tarif`) VALUES
(888999, 'Korea Utara', 'China', '230000');

-- --------------------------------------------------------

--
-- Table structure for table `tracking`
--

CREATE TABLE `tracking` (
  `id_tracking` int(25) NOT NULL,
  `no_resi` int(25) NOT NULL,
  `id_kurir` int(25) NOT NULL,
  `tgl_kirim` date NOT NULL,
  `tgl_sampai` date NOT NULL,
  `status_kirim` varchar(25) NOT NULL,
  `ket` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tracking`
--

INSERT INTO `tracking` (`id_tracking`, `no_resi`, `id_kurir`, `tgl_kirim`, `tgl_sampai`, `status_kirim`, `ket`) VALUES
(130130, 202020, 340340, '2024-06-27', '2024-06-30', 'Package picked up', 'COD');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `barang`
--
ALTER TABLE `barang`
  ADD PRIMARY KEY (`kode_barang`);

--
-- Indexes for table `kurir`
--
ALTER TABLE `kurir`
  ADD PRIMARY KEY (`id_kurir`);

--
-- Indexes for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD PRIMARY KEY (`id_pegawai`);

--
-- Indexes for table `pelanggan`
--
ALTER TABLE `pelanggan`
  ADD PRIMARY KEY (`id_pelanggan`);

--
-- Indexes for table `pengiriman`
--
ALTER TABLE `pengiriman`
  ADD PRIMARY KEY (`no_resi`);

--
-- Indexes for table `tarif`
--
ALTER TABLE `tarif`
  ADD PRIMARY KEY (`id_tarif`);

--
-- Indexes for table `tracking`
--
ALTER TABLE `tracking`
  ADD PRIMARY KEY (`id_tracking`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `barang`
--
ALTER TABLE `barang`
  MODIFY `kode_barang` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=200334;

--
-- AUTO_INCREMENT for table `kurir`
--
ALTER TABLE `kurir`
  MODIFY `id_kurir` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=88000;

--
-- AUTO_INCREMENT for table `pegawai`
--
ALTER TABLE `pegawai`
  MODIFY `id_pegawai` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=300334;

--
-- AUTO_INCREMENT for table `pelanggan`
--
ALTER TABLE `pelanggan`
  MODIFY `id_pelanggan` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=100880;

--
-- AUTO_INCREMENT for table `pengiriman`
--
ALTER TABLE `pengiriman`
  MODIFY `no_resi` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=800913;

--
-- AUTO_INCREMENT for table `tarif`
--
ALTER TABLE `tarif`
  MODIFY `id_tarif` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8676787;

--
-- AUTO_INCREMENT for table `tracking`
--
ALTER TABLE `tracking`
  MODIFY `id_tracking` int(25) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=775766;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
