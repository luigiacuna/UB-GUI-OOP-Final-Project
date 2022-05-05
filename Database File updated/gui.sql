-- phpMyAdmin SQL Dump
-- version 5.1.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Apr 29, 2022 at 08:46 PM
-- Server version: 8.0.28
-- PHP Version: 7.4.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gui`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--
CREATE DATABASE IF NOT EXISTS gui_final;
USE gui_admin;

CREATE TABLE `admin` (
  `id` int DEFAULT '100',
  `Id_no` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `Admin_name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `addPatient` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `removePatient` text COLLATE utf8mb4_general_ci NOT NULL,
  `addDoctor` text COLLATE utf8mb4_general_ci NOT NULL,
  `removeDoctor` text COLLATE utf8mb4_general_ci NOT NULL,
  `addNurse` text COLLATE utf8mb4_general_ci NOT NULL,
  `removeNurse` text COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `Id_no`, `Admin_name`, `addPatient`, `removePatient`, `addDoctor`, `removeDoctor`, `addNurse`, `removeNurse`) VALUES
(NULL, '1335', 'Luigi_A', '', '', '', '', '', ''),
(NULL, '1457', 'Josiah_V', '', '', '', '', '', ''),
(NULL, '4679', 'Abi_A', '', '', '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `doctor`
--

CREATE TABLE `doctor` (
  `Doctor_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL COMMENT 'special id for the doctor',
  `First Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL COMMENT 'first name of doctor',
  `Last Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL COMMENT 'last name of doctor',
  `Position` varchar(255) COLLATE utf8mb4_general_ci NOT NULL COMMENT 'doctor job description',
  `Social Security Number` int NOT NULL COMMENT 'ssn ',
  `Age` int DEFAULT '20' COMMENT 'age',
  `Phone Number` int NOT NULL COMMENT 'phone'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `doctor`
--

INSERT INTO `doctor` (`Doctor_id`, `First Name`, `Last Name`, `Position`, `Social Security Number`, `Age`, `Phone Number`) VALUES
('D670', 'Gina', 'Henry', 'Emergency Physician', 963498, 40, 6709856),
('D742', 'Malachi', 'Henry', 'Pediatrician', 586978, 22, 6705986),
('D765', 'Travis', 'Barker', 'Psychiatrist', 364958, 35, 6149758),
('D768\r\n', 'Omar \r\n', 'Biden\r\n', 'Neurologist', 789456, 45, 6134978),
('D769', 'Emily', 'Barnett', 'Radiologist', 247589, 43, 6154789);

-- --------------------------------------------------------

--
-- Table structure for table `labs`
--

CREATE TABLE `labs` (
  `Lab_No` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Date` date NOT NULL,
  `Test_name` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `test_description` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `patient_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `doctor_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Nurse_id` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `test_result` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Comment` varchar(255) COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `labs`
--

INSERT INTO `labs` (`Lab_No`, `Date`, `Test_name`, `test_description`, `patient_id`, `doctor_id`, `Nurse_id`, `test_result`, `Comment`) VALUES
('L100', '2022-04-08', 'Urine Test', 'Kidney Disease', 'P101', 'D768', '', '\r\nTests patients for any UTI, kidney disease or diabetes', 'Patient to be sent to nurse for pill scheduling'),
('L234', '2022-04-29', 'Pink Eye', 'Tests for level or infection in one or both eyes', 'P124', '', '', 'Infectious conjuctivitis', 'Patient will on on the pill schedule');

-- --------------------------------------------------------

--
-- Table structure for table `nurse`
--

CREATE TABLE `nurse` (
  `Nurse_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `First Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Last Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Position` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Registered` tinyint(1) NOT NULL,
  `Age` int NOT NULL,
  `Gender` varchar(255) COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `nurse`
--

INSERT INTO `nurse` (`Nurse_id`, `First Name`, `Last Name`, `Position`, `Registered`, `Age`, `Gender`) VALUES
('N245', 'Taryn', 'Hill', 'Intensive Care Unit(ICU)', 0, 27, 'Female'),
('N332', 'Rene', 'Villanueva', 'Clinical nurse specialist', 1, 25, 'Male'),
('N333', 'Luigi', 'Acuna', 'Critical Care Specialist', 1, 26, 'Male'),
('N746', 'Carolee', 'Parim', 'Head Nurse', 1, 25, 'Female');

-- --------------------------------------------------------

--
-- Table structure for table `patient`
--

CREATE TABLE `patient` (
  `Patient_id` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `Social Security Number` int NOT NULL,
  `First Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Last Name` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Age` int NOT NULL,
  `Phone Number` int NOT NULL,
  `Email` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Gender` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Date of Birth` date NOT NULL,
  `Address` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Ailment` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Doctor_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Nurse_id` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Comments` text COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `patient`
--

INSERT INTO `patient` (`Patient_id`, `Social Security Number`, `First Name`, `Last Name`, `Age`, `Phone Number`, `Email`, `Gender`, `Date of Birth`, `Address`, `Ailment`, `Doctor_id`, `Nurse_id`, `Comments`) VALUES
('P100', 746596, 'Josiah', 'Velasquez', 21, 6339768, 'jvelasquez@gmail.com', 'Male', '2000-05-05', 'Belmopan City', 'Heart Failure', '', '', ''),
('P101', 154967, 'Kerry', 'Washington', 46, 6345789, 'washingtonkerry@outlook.com', 'Female', '1975-01-15', 'Orange Street, Belmopan', 'Kidney disease', '', '', ''),
('P113', 7847887, 'Luigi', 'Mario', 10, 6697895, 'lmario@outlook.com', 'Male', '2012-04-10', 'Onion Street, Belize city', 'Nausea', '', '', ''),
('P124', 6935896, 'Abi', 'Alvarez', 27, 6369706, 'aalvarez@gmail.com', 'Female', '1995-05-17', 'Kahoot Ave, Dangriga Town', 'Conjunctivitis', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `pill schedule`
--

CREATE TABLE `pill schedule` (
  `Pill code` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Description` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Patient_id` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `Expiry Date` date NOT NULL,
  `Dosage` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `Startdate` date NOT NULL,
  `Endate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pill schedule`
--

INSERT INTO `pill schedule` (`Pill code`, `Name`, `Description`, `Patient_id`, `Expiry Date`, `Dosage`, `Startdate`, `Endate`) VALUES
('C07AB03', 'Atenolol', 'Primarily used to treat high blood pressure and heart-associated chest pain. Atenolol, however, does not seem to improve mortality in those with high blood pressure', 'P100', '2024-04-17', '25 mg Twice a day\r\nOne in the morning, one before bedtime', '2022-04-28', '2022-05-11'),
('CP75', 'Captopril', 'Captopril works by blocking a substance in the body that causes blood vessels to tighten. This lowers blood pressure and increases the supply of blood and oxygen to the heart.', 'P100', '2024-04-17', '25 mg orally every 8-12 hours', '2022-04-15', '2022-05-20');

-- --------------------------------------------------------

--
-- Table structure for table `user login`
--

CREATE TABLE `user login` (
  `id` int NOT NULL,
  `username` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `password` varchar(255) COLLATE utf8mb4_general_ci NOT NULL,
  `old_password` varchar(1000) COLLATE utf8mb4_general_ci NOT NULL,
  `wrong_login_attempt` int NOT NULL,
  `today_login_attempt` int NOT NULL,
  `is_now_login` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT 'NO' COMMENT 'check if user is logged in',
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user login`
--

INSERT INTO `user login` (`id`, `username`, `password`, `old_password`, `wrong_login_attempt`, `today_login_attempt`, `is_now_login`, `date`, `time`) VALUES
(1546, 'aalvarez', 'hellers', 'hellers', 1, 1, 'NO', '2022-04-08', '08:45:00'),
(4857, 'lacuna', 'marioo', 'marioo', 0, 0, 'NO', '2022-04-29', '00:00:00'),
(7695, 'jvelasquez', 'joshiah', 'joshiah', 2, 2, 'NO', '2022-04-29', '00:00:00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`Id_no`),
  ADD UNIQUE KEY `Foreign Key` (`id`) USING BTREE;

--
-- Indexes for table `doctor`
--
ALTER TABLE `doctor`
  ADD PRIMARY KEY (`Doctor_id`);

--
-- Indexes for table `labs`
--
ALTER TABLE `labs`
  ADD PRIMARY KEY (`Lab_No`);

--
-- Indexes for table `nurse`
--
ALTER TABLE `nurse`
  ADD PRIMARY KEY (`Nurse_id`);

--
-- Indexes for table `patient`
--
ALTER TABLE `patient`
  ADD PRIMARY KEY (`Patient_id`),
  ADD KEY `Nurse_id` (`Nurse_id`);

--
-- Indexes for table `pill schedule`
--
ALTER TABLE `pill schedule`
  ADD PRIMARY KEY (`Pill code`);

--
-- Indexes for table `user login`
--
ALTER TABLE `user login`
  ADD PRIMARY KEY (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
