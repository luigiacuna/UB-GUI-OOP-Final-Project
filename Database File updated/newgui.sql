#this sql file will hold all the barebone info that will be needed by the program while it is being created more info will added

CREATE TABLE users(id INT NOT NULL,
				   username varchar(25) UNIQUE,
				   password varchar (50),
				   type varchar (6)
);#creates the users table this holds all the user information without any personal info this will probs be used at the login window to determine which window will be used

CREATE TABLE admin(id INT,
				   username varchar(25),
				   fullname varchar(50)
);#the admin tables more information for the administrator that will create the nurses and doctors

CREATE TABLE doctor(doctor_id INT NOT NULL,
	                username varchar (25) UNIQUE,
	                name varchar (50)
);#the doctor table holds all the doctor personal info

CREATE TABLE nurses(nurse_id INT NOT NULL,
	                username varchar(25) UNIQUE,
	                name varchar(50)

);#the nurses table will hold all the nurse personal credentials

CREATE TABLE patients(patient_id varchar (50) UNIQUE NOT NULL,
                      firstName varchar (50),
                      lastName varchar (50),
					  age int,
					  phonenumber VARCHAR(15),
					  gender VARCHAR(6),
					  dob DATE,
					  socialsecruity VARCHAR(9),
					  doctor_id INT,
					  nurse_id INT


);#the patients table will hold all the patient info that will be used and or created by doctors in which in turn will create their pill schedule

CREATE TABLE schedule(schedule_id int,
	            patient_id varchar (50),
	            med_id varchar(5),
	            dosage_in_num int,
	            dosage_units varchar(5),
				date_start DATE,
				date_end DATE
);#the schedule table will actually hold the scheduling information needed to create the actual pill distributio 

CREATE TABLE medicine(med_id varchar(5),
					  med_name varchar(25)
);
#the meds table will hold all the meds that can be prescribed by the doctor, also the doctor can also add meds that are not in this TABLE


#this section of the file will fill the tables will neccessary table for the users, admin, doctors, and nurses only at program runtime then will patients and schedules are made

INSERT INTO users (id,username,password,type)
VALUES (1,"lacuna","password","admin");

INSERT INTO users (id,username,password,type)
VALUES (2,"jvelasquez","password","doctor");

INSERT INTO users (id,username,password,type)
VALUES (3,"aalvarez","password","nurse");


INSERT INTO admin (id,username,fullname)
VALUES (1,"lacuna","Luigi Acuna");

INSERT INTO doctor (doctor_id,username,name)
VALUES(2,"jvelasquez","Dr. Josiah 'Yeetus Deletus' Velasquez");

INSERT INTO nurses (nurse_id,username,name)
VALUES(3,"aavalrez","Nurse Abi Alvarez the baddess");