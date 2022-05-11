#this sql file will hold all the barebone info that will be needed by the program while it is being created more info will added

CREATE TABLE users(id INT NOT NULL PRIMARY KEY,
				   username varchar(25) UNIQUE,
				   password varchar(50),
				   role varchar (6)
);#creates the users table this holds all the user information without any personal info this will probs be used at the login window to determine which window will be used

CREATE TABLE admin(id INT NOT NULL PRIMARY KEY,
				   username varchar(25),
				   firstname varchar(50),
				   lastname varchar(50),
				   FOREIGN KEY (id) REFERENCES users (id) ON DELETE CASCADE
);#the admin tables more information for the administrator that will create the nurses and doctors

CREATE TABLE doctor(id INT NOT NULL PRIMARY KEY,
	                username varchar (25) UNIQUE,
	                firstname varchar (50),
					lastname varchar(50),
					FOREIGN KEY (id) REFERENCES users (id) ON DELETE CASCADE
);#the doctor table holds all the doctor personal info

CREATE TABLE nurse(id INT NOT NULL PRIMARY KEY,
	                username varchar(25) UNIQUE,
	                firstname varchar(50),
					lastname VARCHAR(50),
					FOREIGN KEY (id) REFERENCES users (id) ON DELETE CASCADE
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
					  FOREIGN KEY (doctor_id) REFERENCES doctor (id)


);#the patients table will hold all the patient info that will be used and or created by doctors in which in turn will create their pill schedule

CREATE TABLE schedule(schedule_id int PRIMARY KEY,
	                  patient_id varchar (50),
					  med_id varchar(5) UNIQUE,
	                  dosage_in_num int,
	                  dosage_units varchar(5),
				      date_start DATE,
				      date_end DATE,
					  nurse_id int,
				      FOREIGN KEY (patient_id) REFERENCES patients (patient_id),
					  FOREIGN KEY (nurse_id) REFERENCES nurse (id)
);#the schedule table will actually hold the scheduling information needed to create the actual pill distributio 

CREATE TABLE medicine(med_id varchar(5) PRIMARY KEY UNIQUE,
					  med_name varchar(25)
);
#the meds table will hold all the meds that can be prescribed by the doctor, also the doctor can also add meds that are not in this TABLE

CREATE TABLE logs (schedule_id int PRIMARY KEY,
                   logData VARCHAR(5475),
				   FOREIGN KEY (schedule_id) REFERENCES schedule (schedule_id)
);


#this section of the file will fill the tables will neccessary table for the users, admin, doctors, and nurses only at program runtime then will patients and schedules are made

INSERT INTO users (id,username,password,role)
VALUES (1,"lacuna","password","admin");

INSERT INTO users (id,username,password,role)
VALUES (2,"jvelasquez","password","doctor");

INSERT INTO users (id,username,password,role)
VALUES (3,"aalvarez","password","nurse");


INSERT INTO admin (id,username,firstname,lastname)
VALUES (1,"lacuna","Luigi","Acuna");

INSERT INTO doctor (id,username,firstname,lastname)
VALUES(2,"jvelasquez","Josiah 'Yeetus Deletus'", "Velasquez");

INSERT INTO nurse (id,username,firstname,lastname)
VALUES(3,"aavalrez","Abi", "Alvarez the baddess");
