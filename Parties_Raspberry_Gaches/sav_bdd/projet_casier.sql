-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : ven. 09 avr. 2021 à 10:16
-- Version du serveur :  10.3.27-MariaDB-0+deb10u1
-- Version de PHP : 7.3.27-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `projet_casier`
--

-- --------------------------------------------------------

--
-- Structure de la table `ADHERENTS`
--

CREATE TABLE `ADHERENTS` (
  `idadherent` int(42) NOT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `prenom` varchar(20) DEFAULT NULL,
  `numcarte` int(10) DEFAULT NULL,
  `numadherent` int(20) DEFAULT NULL,
  `compteur` int(10) DEFAULT NULL,
  `idclasse_1` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `ADHERENTS`
--

INSERT INTO `ADHERENTS` (`idadherent`, `nom`, `prenom`, `numcarte`, `numadherent`, `compteur`, `idclasse_1`) VALUES
(1, 'Castex', 'Jean', 12345, 2361, 0, 1),
(2, 'Bai', 'Tom', 78965, 2650, 0, 2),
(3, 'Riqueau', 'Nicolas', 56966, 5588, 0, 2),
(4, 'Arteau', 'Thomas', 11667, 1667, 0, 3),
(5, 'Liaine', 'Léo', 55238, 1566, 0, 2);

-- --------------------------------------------------------

--
-- Structure de la table `ADMIN`
--

CREATE TABLE `ADMIN` (
  `idadmin` int(10) NOT NULL,
  `login` varchar(50) DEFAULT NULL,
  `mdp` varchar(50) DEFAULT NULL,
  `nomadmin` varchar(50) DEFAULT NULL,
  `prenomadmin` varchar(20) DEFAULT NULL,
  `privilege` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `ADMIN`
--

INSERT INTO `ADMIN` (`idadmin`, `login`, `mdp`, `nomadmin`, `prenomadmin`, `privilege`) VALUES
(1, 'projet_casier', 'snir2', 'Snir', 'Axel', 1);

-- --------------------------------------------------------

--
-- Structure de la table `CASIER`
--

CREATE TABLE `CASIER` (
  `idcasier` int(10) NOT NULL,
  `positionx` int(3) DEFAULT NULL,
  `positiony` int(4) DEFAULT NULL,
  `rendu` tinyint(1) DEFAULT NULL,
  `idmateriel` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `CASIER`
--

INSERT INTO `CASIER` (`idcasier`, `positionx`, `positiony`, `rendu`, `idmateriel`) VALUES
(1, 0, 1, 0, 1),
(2, 2, 1, 0, 2);

-- --------------------------------------------------------

--
-- Structure de la table `CLASSE`
--

CREATE TABLE `CLASSE` (
  `idclasse` int(10) NOT NULL,
  `classe` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `CLASSE`
--

INSERT INTO `CLASSE` (`idclasse`, `classe`) VALUES
(1, 'SNIR1'),
(2, 'SNIR2'),
(3, 'PROFS');

-- --------------------------------------------------------

--
-- Structure de la table `MATERIEL`
--

CREATE TABLE `MATERIEL` (
  `idmateriel` int(10) NOT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `idstatut` int(10) DEFAULT NULL,
  `idtype` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `MATERIEL`
--

INSERT INTO `MATERIEL` (`idmateriel`, `nom`, `idstatut`, `idtype`) VALUES
(1, 'Calculatrice_01', 1, 1),
(2, 'Ballon_01', 2, 2);

-- --------------------------------------------------------

--
-- Structure de la table `PRETERA`
--

CREATE TABLE `PRETERA` (
  `idpret` int(42) NOT NULL,
  `idadherent` int(10) DEFAULT NULL,
  `idmateriel` int(10) DEFAULT NULL,
  `datedebut` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `PRETERA`
--

INSERT INTO `PRETERA` (`idpret`, `idadherent`, `idmateriel`, `datedebut`) VALUES
(1, 1, 1, '2021-03-01 14:12:25'),
(2, 1, 1, '2021-01-11 09:43:16'),
(3, 2, 1, '2021-03-05 18:14:24'),
(4, 3, 2, '2021-03-08 14:09:28'),
(5, 4, 2, '2021-02-10 11:05:30'),
(6, 5, 1, '2020-12-09 15:49:17'),
(7, 5, 2, '2021-03-31 14:07:24'),
(8, 2, 2, '2021-04-01 06:31:19'),
(9, 1, 1, '2021-05-19 12:37:20'),
(10, 4, 2, '2021-03-15 09:12:13'),
(11, 4, 1, '2020-11-17 12:19:40'),
(12, 3, 1, '2020-11-02 16:14:16');

-- --------------------------------------------------------

--
-- Structure de la table `SMS`
--

CREATE TABLE `SMS` (
  `idsms` int(10) NOT NULL,
  `numtel` int(10) DEFAULT NULL,
  `msgsms` varchar(250) DEFAULT NULL,
  `dateenvoie` datetime DEFAULT NULL,
  `idadherent` int(10) DEFAULT NULL,
  `idadmin` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `STATUT`
--

CREATE TABLE `STATUT` (
  `idstatut` int(10) NOT NULL,
  `statut` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `STATUT`
--

INSERT INTO `STATUT` (`idstatut`, `statut`) VALUES
(1, 'DISPONNIBLE'),
(2, 'INDISPONNIBLE'),
(3, 'VOLE'),
(4, 'CASSE');

-- --------------------------------------------------------

--
-- Structure de la table `TYPE`
--

CREATE TABLE `TYPE` (
  `idtype` int(10) NOT NULL,
  `nomtype` varchar(30) DEFAULT NULL,
  `compteur` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `TYPE`
--

INSERT INTO `TYPE` (`idtype`, `nomtype`, `compteur`) VALUES
(1, 'Calculatrice', 0),
(2, 'Ballon', 0),
(3, 'Blouse', 0);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `ADHERENTS`
--
ALTER TABLE `ADHERENTS`
  ADD PRIMARY KEY (`idadherent`),
  ADD KEY `idclasse_1` (`idclasse_1`);

--
-- Index pour la table `ADMIN`
--
ALTER TABLE `ADMIN`
  ADD PRIMARY KEY (`idadmin`);

--
-- Index pour la table `CASIER`
--
ALTER TABLE `CASIER`
  ADD PRIMARY KEY (`idcasier`),
  ADD KEY `idmateriel` (`idmateriel`);

--
-- Index pour la table `CLASSE`
--
ALTER TABLE `CLASSE`
  ADD PRIMARY KEY (`idclasse`);

--
-- Index pour la table `MATERIEL`
--
ALTER TABLE `MATERIEL`
  ADD PRIMARY KEY (`idmateriel`),
  ADD KEY `idtype` (`idtype`),
  ADD KEY `idstatut` (`idstatut`);

--
-- Index pour la table `PRETERA`
--
ALTER TABLE `PRETERA`
  ADD PRIMARY KEY (`idpret`),
  ADD KEY `idmateriel` (`idmateriel`),
  ADD KEY `idadherent` (`idadherent`);

--
-- Index pour la table `SMS`
--
ALTER TABLE `SMS`
  ADD PRIMARY KEY (`idsms`),
  ADD KEY `idadmin` (`idadmin`),
  ADD KEY `idadherent` (`idadherent`);

--
-- Index pour la table `STATUT`
--
ALTER TABLE `STATUT`
  ADD PRIMARY KEY (`idstatut`);

--
-- Index pour la table `TYPE`
--
ALTER TABLE `TYPE`
  ADD PRIMARY KEY (`idtype`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `ADHERENTS`
--
ALTER TABLE `ADHERENTS`
  MODIFY `idadherent` int(42) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT pour la table `ADMIN`
--
ALTER TABLE `ADMIN`
  MODIFY `idadmin` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `CASIER`
--
ALTER TABLE `CASIER`
  MODIFY `idcasier` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `CLASSE`
--
ALTER TABLE `CLASSE`
  MODIFY `idclasse` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `MATERIEL`
--
ALTER TABLE `MATERIEL`
  MODIFY `idmateriel` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `PRETERA`
--
ALTER TABLE `PRETERA`
  MODIFY `idpret` int(42) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT pour la table `SMS`
--
ALTER TABLE `SMS`
  MODIFY `idsms` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `STATUT`
--
ALTER TABLE `STATUT`
  MODIFY `idstatut` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `TYPE`
--
ALTER TABLE `TYPE`
  MODIFY `idtype` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `ADHERENTS`
--
ALTER TABLE `ADHERENTS`
  ADD CONSTRAINT `ADHERENTS_ibfk_1` FOREIGN KEY (`idclasse_1`) REFERENCES `CLASSE` (`idclasse`);

--
-- Contraintes pour la table `CASIER`
--
ALTER TABLE `CASIER`
  ADD CONSTRAINT `CASIER_ibfk_1` FOREIGN KEY (`idmateriel`) REFERENCES `MATERIEL` (`idmateriel`);

--
-- Contraintes pour la table `MATERIEL`
--
ALTER TABLE `MATERIEL`
  ADD CONSTRAINT `MATERIEL_ibfk_1` FOREIGN KEY (`idtype`) REFERENCES `TYPE` (`idtype`),
  ADD CONSTRAINT `MATERIEL_ibfk_2` FOREIGN KEY (`idstatut`) REFERENCES `STATUT` (`idstatut`);

--
-- Contraintes pour la table `PRETERA`
--
ALTER TABLE `PRETERA`
  ADD CONSTRAINT `PRETERA_ibfk_1` FOREIGN KEY (`idmateriel`) REFERENCES `MATERIEL` (`idmateriel`),
  ADD CONSTRAINT `PRETERA_ibfk_2` FOREIGN KEY (`idadherent`) REFERENCES `ADHERENTS` (`idadherent`);

--
-- Contraintes pour la table `SMS`
--
ALTER TABLE `SMS`
  ADD CONSTRAINT `SMS_ibfk_1` FOREIGN KEY (`idadmin`) REFERENCES `ADMIN` (`idadmin`),
  ADD CONSTRAINT `SMS_ibfk_2` FOREIGN KEY (`idadherent`) REFERENCES `ADHERENTS` (`idadherent`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
