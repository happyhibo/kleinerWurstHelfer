--
-- File generated with SQLiteStudio v3.2.1 on Do Aug 29 18:51:52 2019
--
-- Text encoding used: System
--

-- Table: darmliste
CREATE TABLE darmliste (ID INTEGER NOT NULL PRIMARY KEY, d_art TEXT, d_einheit TEXT, d_preis_p_einh DECIMAL (5,3), d_durchmesser INTEGER);

INSERT INTO darmliste (ID, d_art, d_einheit, d_preis_p_einh, d_durchmesser) VALUES (1, '', '', '', '');
INSERT INTO darmliste (ID, d_art, d_einheit, d_preis_p_einh, d_durchmesser) VALUES (2, 'kein Darm', '', '', '');
INSERT INTO darmliste (ID, d_art, d_einheit, d_preis_p_einh, d_durchmesser) VALUES (3, 'Schafsaitling 20/22', '4', 0.23, 21);
INSERT INTO darmliste (ID, d_art, d_einheit, d_preis_p_einh, d_durchmesser) VALUES (4, 'Schafsaitling 22/24', '4', 0.26, 23);
INSERT INTO darmliste (ID, d_art, d_einheit, d_preis_p_einh, d_durchmesser) VALUES (5, 'Schafsaitling 24/26', '4', 0.32, 25);

-- Table: einheiten
CREATE TABLE einheiten (ID INTEGER NOT NULL PRIMARY KEY, e_name TEXT, e_kurzzeichen TEXT);

INSERT INTO einheiten (ID, e_name, e_kurzzeichen) VALUES (1, '', '');
INSERT INTO einheiten (ID, e_name, e_kurzzeichen) VALUES (2, 'Gramm', 'g');
INSERT INTO einheiten (ID, e_name, e_kurzzeichen) VALUES (3, 'Kilogramm', 'kg');
INSERT INTO einheiten (ID, e_name, e_kurzzeichen) VALUES (4, 'Meter', 'm');
INSERT INTO einheiten (ID, e_name, e_kurzzeichen) VALUES (5, 'Stück', 'stk');

-- Table: rezept_pos_fleisch
CREATE TABLE rezept_pos_fleisch (ID INTEGER NOT NULL PRIMARY KEY, rpf_rezept_id INTEGER, rpf_zutat TEXT, rpf_menge_prozent INTEGER, rpf_verarbeitung TEXT, rpf_bemerkung TEXT);

INSERT INTO rezept_pos_fleisch (ID, rpf_rezept_id, rpf_zutat, rpf_menge_prozent, rpf_verarbeitung, rpf_bemerkung) VALUES (1, 1, '2', 50, '2', NULL);
INSERT INTO rezept_pos_fleisch (ID, rpf_rezept_id, rpf_zutat, rpf_menge_prozent, rpf_verarbeitung, rpf_bemerkung) VALUES (2, 1, '4', 50, '2', NULL);

-- Table: rezept_pos_gewuerze
CREATE TABLE rezept_pos_gewuerze (ID INTEGER NOT NULL PRIMARY KEY, rpg_rezept_id INTEGER, rpg_zutat TEXT, rpg_menge_einheit DOUBLE, rpg_einheit TEXT, rpg_verarbeitung TEXT, rpg_bemerkung TEXT);

INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (1, 1, '5', 1.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (2, 1, '6', 1.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (3, 1, '7', 1.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (4, 1, '8', 2.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (5, 1, '4', 2.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (6, 1, '9', 2.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (7, 1, '2', 20.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (8, 1, '12', 1.0, '2', '1', NULL);
INSERT INTO rezept_pos_gewuerze (ID, rpg_rezept_id, rpg_zutat, rpg_menge_einheit, rpg_einheit, rpg_verarbeitung, rpg_bemerkung) VALUES (9, 1, '11', 1.0, '2', '1', NULL);

-- Table: rezept_pos_zubereitung
CREATE TABLE rezept_pos_zubereitung (ID INTEGER NOT NULL PRIMARY KEY, rpz_rezept_id INTEGER, rpz_zubereitung TEXT);

INSERT INTO rezept_pos_zubereitung (ID, rpz_rezept_id, rpz_zubereitung) VALUES (1, 1, 'Fleisch für den Fleischwolf geeignete Stücke schneiden. 
Anfrieren lassen! 
Gewürze mit dem Fleischstücken vermengen. 
Fleisch mit der angegebenen Scheibe(n) wolfen. 
Mit dem Knethaken und Crashed-Eis auf mitllere Geschwindigkeit klebrig rühren. Eis protionsweise zugeben. 
  
Därme vor dem aufziehen warm (37°C) wässern! 

Brät in angegebenen Darm füllen und portionsweiße abdrehen.');

-- Table: rezeptliste
CREATE TABLE rezeptliste (ID INTEGER NOT NULL PRIMARY KEY, r_name TEXT, r_art INTEGER, r_darm INTEGER, r_zubereitung [INTEGER ', R_BEMERKUNG' TEXT], r_erstellt DATETIME);

INSERT INTO rezeptliste (ID, r_name, r_art, r_darm, r_zubereitung, r_erstellt) VALUES (1, 'Bratwurst', 3, 4, 1, '2019-08-26T22:02:23');

-- Table: verarbeitung
CREATE TABLE verarbeitung (ID INTEGER NOT NULL PRIMARY KEY, v_art TEXT);

INSERT INTO verarbeitung (ID, v_art) VALUES (1, '');
INSERT INTO verarbeitung (ID, v_art) VALUES (2, 'Durch 3 mm Scheibe wolfen');
INSERT INTO verarbeitung (ID, v_art) VALUES (3, 'Durch 4,5 mm Scheibe wolfen');
INSERT INTO verarbeitung (ID, v_art) VALUES (4, 'Durch 6 mm Scheibe wolfen');
INSERT INTO verarbeitung (ID, v_art) VALUES (5, 'Durch 8 mm Scheibe wolfen');
INSERT INTO verarbeitung (ID, v_art) VALUES (6, 'geschrotet');

-- Table: wurstarten
CREATE TABLE wurstarten (ID INTEGER NOT NULL PRIMARY KEY, w_wurstart TEXT);

INSERT INTO wurstarten (ID, w_wurstart) VALUES (1, '');
INSERT INTO wurstarten (ID, w_wurstart) VALUES (2, 'Rohwurst');
INSERT INTO wurstarten (ID, w_wurstart) VALUES (3, 'Grillwurst');
INSERT INTO wurstarten (ID, w_wurstart) VALUES (4, 'Kochwurst');
INSERT INTO wurstarten (ID, w_wurstart) VALUES (5, 'Brühwurst');

-- Table: zutatenliste_fleisch
CREATE TABLE zutatenliste_fleisch (ID INTEGER NOT NULL PRIMARY KEY, zlf_name TEXT, zlf_fettanteil DECIMAL (5,2), zlf_verschnitt INTEGER, zlf_einheit TEXT, zlf_preis_p_einh DECIMAL (5,3));

INSERT INTO zutatenliste_fleisch (ID, zlf_name, zlf_fettanteil, zlf_verschnitt, zlf_einheit, zlf_preis_p_einh) VALUES (1, '', '', '', '', '');
INSERT INTO zutatenliste_fleisch (ID, zlf_name, zlf_fettanteil, zlf_verschnitt, zlf_einheit, zlf_preis_p_einh) VALUES (2, 'Schweinebauch', 20, 10, '3', 6.2);
INSERT INTO zutatenliste_fleisch (ID, zlf_name, zlf_fettanteil, zlf_verschnitt, zlf_einheit, zlf_preis_p_einh) VALUES (4, 'Schweinenacken', 20, 10, '3', 6.4);

-- Table: zutatenliste_gewuerze
CREATE TABLE zutatenliste_gewuerze (ID INTEGER NOT NULL PRIMARY KEY, zlg_name TEXT, zlg_einheit TEXT, zlg_preis_p_einh DECIMAL (5,3));

INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (1, '', '', '');
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (2, 'Salz (Speisesalz)', '2', 0.0068);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (3, 'Pfeffer weiß', '2', 0.02);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (4, 'Pfeffer schwarz', '2', 0.02);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (5, 'Cayennepfeffer', '2', 0.02);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (6, 'Macis (Muskatblüte)', '2', 0.035);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (7, 'Muskat', '2', 0.0275);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (8, 'Majoran', '2', 0.025);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (9, 'Selleriesalz', '2', 0.02);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (11, 'Knoblauchpulver', '2', 0.02);
INSERT INTO zutatenliste_gewuerze (ID, zlg_name, zlg_einheit, zlg_preis_p_einh) VALUES (12, 'Zwiebelpulver', '2', 0.02);

