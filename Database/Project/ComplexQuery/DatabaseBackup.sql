PGDMP  "                    |            hotelbookingdatabase    16.1 (Debian 16.1-1.pgdg120+1)    16.1 I    l           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            m           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            n           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            o           1262    49806    hotelbookingdatabase    DATABASE        CREATE DATABASE hotelbookingdatabase WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'en_US.utf8';
 $   DROP DATABASE hotelbookingdatabase;
                root    false            �            1255    49904 g   add_user(character varying, character varying, character varying, character varying, character varying)    FUNCTION     -  CREATE FUNCTION public.add_user(firstname character varying, lastname character varying, emaill character varying, passcode character varying, telephonenumber character varying) RETURNS boolean
    LANGUAGE plpgsql
    AS $$
DECLARE 
	checkemail VARCHAR(255);
    rn INTEGER;
BEGIN
	SELECT userName.email
	INTO checkemail
	FROM userName
	WHERE emaill = userName.email;
	
    IF FOUND THEN
        RETURN FALSE;
    END IF;
    
    INSERT INTO UserName VALUES
    (DEFAULT, firstname, lastname, emaill, passcode, telephoneNumber);
	
	RETURN TRUE;

END;
$$;
 �   DROP FUNCTION public.add_user(firstname character varying, lastname character varying, emaill character varying, passcode character varying, telephonenumber character varying);
       public          root    false            �            1255    49914 &   admin_delete_booking(integer, integer) 	   PROCEDURE     �  CREATE PROCEDURE public.admin_delete_booking(IN adminuserid integer, IN deletebookingid integer)
    LANGUAGE plpgsql
    AS $$
DECLARE
    adminId INTEGER;
BEGIN 
    SELECT admin.userId
    INTO adminId
    FROM admin
    WHERE admin.userId = adminuserId;

    IF NOT FOUND THEN
        RETURN;
    ELSE
        DELETE FROM booking WHERE booking.bookingId = deletebookingID;
        RETURN;
    END IF;
END;
$$;
 `   DROP PROCEDURE public.admin_delete_booking(IN adminuserid integer, IN deletebookingid integer);
       public          root    false            �            1255    49913 i   admin_edit_booking(integer, character varying, date, date, timestamp without time zone, integer, integer) 	   PROCEDURE       CREATE PROCEDURE public.admin_edit_booking(IN booking_id integer, IN booking_status character varying, IN start_date date, IN end_date date, IN creationdate timestamp without time zone, IN room_id integer, IN edituser integer)
    LANGUAGE plpgsql
    AS $$
DECLARE
    realhotelID INTEGER;
BEGIN 
    SELECT Admin.hotelID
    INTO realhotelID
    FROM Admin
    WHERE Admin.userID = edituser;

    IF NOT FOUND THEN
        RETURN;
    ELSE
        UPDATE booking set bookingStatus = booking_Status,
                            startdate = start_date,
                            enddate = end_date,
                            creation_date = NOW(),
                            roomid = room_id
        
        where bookingID = booking_ID;
        RETURN;
    END IF;
END;
$$;
 �   DROP PROCEDURE public.admin_edit_booking(IN booking_id integer, IN booking_status character varying, IN start_date date, IN end_date date, IN creationdate timestamp without time zone, IN room_id integer, IN edituser integer);
       public          root    false            �            1255    49912    admin_view_booking(integer)    FUNCTION     �  CREATE FUNCTION public.admin_view_booking(inuserid integer) RETURNS TABLE(bookingid integer, firstname character varying, lastname character varying, bookingstatus character varying, startdate date, enddate date, roomtype character varying)
    LANGUAGE plpgsql
    AS $$
DECLARE 
    userhotelID INTEGER;
BEGIN
SELECT A.hotelID
INTO userhotelID
FROM Admin A
WHERE InuserID = A.UserID;

IF NOT FOUND THEN
    RETURN NEXT;
END IF;

RETURN QUERY
SELECT DISTINCT B.bookingID, U.firstname, U.lastname, B.bookingStatus, B.startDate, B.endDate, R.typeName
FROM Booking B, UserName U, Room R
WHERE B.userID = U.userID and B.hotelID = userhotelID and B.roomID = R.roomID;


END;
$$;
 ;   DROP FUNCTION public.admin_view_booking(inuserid integer);
       public          root    false            �            1255    49908 4   booking_hotel(date, date, integer, integer, integer)    FUNCTION     3  CREATE FUNCTION public.booking_hotel(in_startdate date, in_enddate date, hotel_id integer, room_id integer, user_id integer) RETURNS boolean
    LANGUAGE plpgsql
    AS $$
BEGIN
    INSERT INTO booking VALUES(user_Id, DEFAULT, 1,in_startdate, in_enddate, NOW(), room_id, hotel_id);
    RETURN TRUE;
END $$;
 |   DROP FUNCTION public.booking_hotel(in_startdate date, in_enddate date, hotel_id integer, room_id integer, user_id integer);
       public          root    false            �            1255    49911 '   delete_hotel_bookings(integer, integer) 	   PROCEDURE     �   CREATE PROCEDURE public.delete_hotel_bookings(IN userid integer, IN booking_id integer)
    LANGUAGE plpgsql
    AS $$
BEGIN 
    DELETE FROM booking B where booking_ID = B.bookingID;
END;
$$;
 W   DROP PROCEDURE public.delete_hotel_bookings(IN userid integer, IN booking_id integer);
       public          root    false            �            1255    49910 j   edit_hotel_bookings(integer, character varying, date, date, timestamp without time zone, integer, integer) 	   PROCEDURE     �  CREATE PROCEDURE public.edit_hotel_bookings(IN booking_id integer, IN booking_status character varying, IN start_date date, IN end_date date, IN creationdate timestamp without time zone, IN room_id integer, IN hotel_id integer)
    LANGUAGE plpgsql
    AS $$
DECLARE
    realhotelID INTEGER;
BEGIN 
    UPDATE booking SET bookingStatus = booking_status,
                        startdate = start_date,
                        enddate = end_date,
                        creation_date = NOW(),
                        roomid = room_id,
                        hotelid = hotel_id
        
        WHERE bookingID = booking_ID;
        RETURN;
END;
$$;
 �   DROP PROCEDURE public.edit_hotel_bookings(IN booking_id integer, IN booking_status character varying, IN start_date date, IN end_date date, IN creationdate timestamp without time zone, IN room_id integer, IN hotel_id integer);
       public          root    false            �            1255    49907    hotel_list(date, date)    FUNCTION     �  CREATE FUNCTION public.hotel_list(in_startdate date, in_enddate date) RETURNS TABLE(hotelname character varying, roomtype character varying, buildingno character varying, street character varying, subdistrictname character varying, districtname character varying, province character varying, postalcode character varying, email character varying)
    LANGUAGE plpgsql
    AS $$
BEGIN
    IF (in_endDate - in_startDate) <= 4 THEN
        RETURN QUERY
        SELECT h.name,
               rt.typeName,
               h.buildingNo,
               h.street,
               h.subDistrictName,
               h.districtName,
               h.province,
               h.postalCode,
               h.email
        FROM room R
        JOIN Hotel h ON R.hotelId = h.hotelId
        JOIN RoomType rt ON R.typeName = rt.typeName
        WHERE NOT EXISTS (
            SELECT 1
            FROM Booking b
            WHERE R.roomId = b.roomId
              AND h.hotelId = b.hotelId
              AND ((in_startDate BETWEEN b.startDate AND b.endDate) OR (in_endDate BETWEEN b.startDate AND b.endDate))
        );
    ELSE
        RETURN NEXT;
    END IF;
END;
$$;
 E   DROP FUNCTION public.hotel_list(in_startdate date, in_enddate date);
       public          root    false            �            1255    49905 ,   log_in(character varying, character varying)    FUNCTION     Y  CREATE FUNCTION public.log_in(emaill character varying, passcodee character varying) RETURNS boolean
    LANGUAGE plpgsql
    AS $$
DECLARE
    realpasscode VARCHAR(255);
    realuserID INTEGER;
BEGIN
    SELECT u.passcode, u.userID
    INTO realpasscode,realuserID
    FROM UserName u
    WHERE u.email = emaill;
    
    IF NOT FOUND THEN 
        RETURN FALSE;
    ELSE
        IF realpasscode = passcodee THEN
            INSERT INTO loggedin VALUES (DEFAULT, realuserID, emaill,'login', now());
            RETURN TRUE;
        ELSE
            RETURN FALSE;
        END IF;
    END IF;
END;
$$;
 T   DROP FUNCTION public.log_in(emaill character varying, passcodee character varying);
       public          root    false            �            1255    49906    log_out(character varying) 	   PROCEDURE     >  CREATE PROCEDURE public.log_out(IN emaill character varying)
    LANGUAGE plpgsql
    AS $$
DECLARE
    realuserID INTEGER;
BEGIN
    SELECT u.userID
    INTO realuserID
    FROM UserName u
    WHERE u.email = emaill;
    INSERT INTO loggedin VALUES (DEFAULT, realuserID, emaill,'logout', now());
    COMMIT;
END;
$$;
 <   DROP PROCEDURE public.log_out(IN emaill character varying);
       public          root    false            �            1255    49909    view_hotel_bookings(integer)    FUNCTION     �  CREATE FUNCTION public.view_hotel_bookings(inuserid integer) RETURNS TABLE(bookingid integer, bookingstatus character varying, startdate date, enddate date, roomtype character varying, hotelname character varying)
    LANGUAGE plpgsql
    AS $$
 
BEGIN

RETURN QUERY
SELECT DISTINCT B.bookingID, B.bookingStatus, B.startDate, B.endDate, R.typeName, H.name
FROM Booking B, UserName U, Room R, Hotel H
WHERE B.userID = Inuserid and  B.roomID = R.roomID and H.hotelID = B.hotelID;


END;
$$;
 <   DROP FUNCTION public.view_hotel_bookings(inuserid integer);
       public          root    false            �            1259    49879    admin    TABLE     Y   CREATE TABLE public.admin (
    userid integer NOT NULL,
    hotelid integer NOT NULL
);
    DROP TABLE public.admin;
       public         heap    root    false            �            1259    49863    booking    TABLE     ;  CREATE TABLE public.booking (
    userid integer NOT NULL,
    bookingid integer NOT NULL,
    bookingstatus character varying(255) NOT NULL,
    startdate date NOT NULL,
    enddate date NOT NULL,
    creation_date timestamp without time zone NOT NULL,
    roomid integer NOT NULL,
    hotelid integer NOT NULL
);
    DROP TABLE public.booking;
       public         heap    root    false            �            1259    49862    booking_bookingid_seq    SEQUENCE     �   CREATE SEQUENCE public.booking_bookingid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 ,   DROP SEQUENCE public.booking_bookingid_seq;
       public          root    false    226            p           0    0    booking_bookingid_seq    SEQUENCE OWNED BY     O   ALTER SEQUENCE public.booking_bookingid_seq OWNED BY public.booking.bookingid;
          public          root    false    225            �            1259    49819    hotel    TABLE     �  CREATE TABLE public.hotel (
    hotelid integer NOT NULL,
    name character varying(255) NOT NULL,
    telephonenumber character varying(10) NOT NULL,
    email character varying(255),
    buildingno character varying(10) NOT NULL,
    street character varying(255),
    subdistrictname character varying(255) NOT NULL,
    districtname character varying(255) NOT NULL,
    province character varying(255) NOT NULL,
    postalcode character varying(5) NOT NULL
);
    DROP TABLE public.hotel;
       public         heap    root    false            �            1259    49818    hotel_hotelid_seq    SEQUENCE     �   CREATE SEQUENCE public.hotel_hotelid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 (   DROP SEQUENCE public.hotel_hotelid_seq;
       public          root    false    218            q           0    0    hotel_hotelid_seq    SEQUENCE OWNED BY     G   ALTER SEQUENCE public.hotel_hotelid_seq OWNED BY public.hotel.hotelid;
          public          root    false    217            �            1259    49893    loggedin    TABLE     �   CREATE TABLE public.loggedin (
    logid integer NOT NULL,
    userid integer NOT NULL,
    email character varying(255),
    logtype character varying(6),
    loggedtime timestamp without time zone
);
    DROP TABLE public.loggedin;
       public         heap    root    false            �            1259    49892    loggedin_logid_seq    SEQUENCE     �   CREATE SEQUENCE public.loggedin_logid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 )   DROP SEQUENCE public.loggedin_logid_seq;
       public          root    false    229            r           0    0    loggedin_logid_seq    SEQUENCE OWNED BY     I   ALTER SEQUENCE public.loggedin_logid_seq OWNED BY public.loggedin.logid;
          public          root    false    228            �            1259    49851    review    TABLE     �   CREATE TABLE public.review (
    reviewid integer NOT NULL,
    messages character varying(255),
    rating numeric NOT NULL,
    hotelid integer NOT NULL
);
    DROP TABLE public.review;
       public         heap    root    false            �            1259    49850    review_reviewid_seq    SEQUENCE     �   CREATE SEQUENCE public.review_reviewid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 *   DROP SEQUENCE public.review_reviewid_seq;
       public          root    false    224            s           0    0    review_reviewid_seq    SEQUENCE OWNED BY     K   ALTER SEQUENCE public.review_reviewid_seq OWNED BY public.review.reviewid;
          public          root    false    223            �            1259    49836    room    TABLE     �   CREATE TABLE public.room (
    hotelid integer NOT NULL,
    roomid integer NOT NULL,
    roomnumber integer NOT NULL,
    roomstatus character varying(255) NOT NULL,
    typename character varying(255) NOT NULL
);
    DROP TABLE public.room;
       public         heap    root    false            �            1259    49834    room_hotelid_seq    SEQUENCE     �   CREATE SEQUENCE public.room_hotelid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 '   DROP SEQUENCE public.room_hotelid_seq;
       public          root    false    222            t           0    0    room_hotelid_seq    SEQUENCE OWNED BY     E   ALTER SEQUENCE public.room_hotelid_seq OWNED BY public.room.hotelid;
          public          root    false    220            �            1259    49835    room_roomid_seq    SEQUENCE     �   CREATE SEQUENCE public.room_roomid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.room_roomid_seq;
       public          root    false    222            u           0    0    room_roomid_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.room_roomid_seq OWNED BY public.room.roomid;
          public          root    false    221            �            1259    49827    roomtype    TABLE     �   CREATE TABLE public.roomtype (
    typename character varying(255) NOT NULL,
    maxoccupant integer NOT NULL,
    amenities character varying(255) NOT NULL,
    price integer NOT NULL
);
    DROP TABLE public.roomtype;
       public         heap    root    false            �            1259    49808    username    TABLE     (  CREATE TABLE public.username (
    userid integer NOT NULL,
    firstname character varying(255) NOT NULL,
    lastname character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    passcode character varying(255) NOT NULL,
    telephonenumber character varying(10) NOT NULL
);
    DROP TABLE public.username;
       public         heap    root    false            �            1259    49807    username_userid_seq    SEQUENCE     �   CREATE SEQUENCE public.username_userid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 *   DROP SEQUENCE public.username_userid_seq;
       public          root    false    216            v           0    0    username_userid_seq    SEQUENCE OWNED BY     K   ALTER SEQUENCE public.username_userid_seq OWNED BY public.username.userid;
          public          root    false    215            �           2604    49866    booking bookingid    DEFAULT     v   ALTER TABLE ONLY public.booking ALTER COLUMN bookingid SET DEFAULT nextval('public.booking_bookingid_seq'::regclass);
 @   ALTER TABLE public.booking ALTER COLUMN bookingid DROP DEFAULT;
       public          root    false    225    226    226            �           2604    49822    hotel hotelid    DEFAULT     n   ALTER TABLE ONLY public.hotel ALTER COLUMN hotelid SET DEFAULT nextval('public.hotel_hotelid_seq'::regclass);
 <   ALTER TABLE public.hotel ALTER COLUMN hotelid DROP DEFAULT;
       public          root    false    217    218    218            �           2604    49896    loggedin logid    DEFAULT     p   ALTER TABLE ONLY public.loggedin ALTER COLUMN logid SET DEFAULT nextval('public.loggedin_logid_seq'::regclass);
 =   ALTER TABLE public.loggedin ALTER COLUMN logid DROP DEFAULT;
       public          root    false    228    229    229            �           2604    49854    review reviewid    DEFAULT     r   ALTER TABLE ONLY public.review ALTER COLUMN reviewid SET DEFAULT nextval('public.review_reviewid_seq'::regclass);
 >   ALTER TABLE public.review ALTER COLUMN reviewid DROP DEFAULT;
       public          root    false    224    223    224            �           2604    49839    room hotelid    DEFAULT     l   ALTER TABLE ONLY public.room ALTER COLUMN hotelid SET DEFAULT nextval('public.room_hotelid_seq'::regclass);
 ;   ALTER TABLE public.room ALTER COLUMN hotelid DROP DEFAULT;
       public          root    false    222    220    222            �           2604    49840    room roomid    DEFAULT     j   ALTER TABLE ONLY public.room ALTER COLUMN roomid SET DEFAULT nextval('public.room_roomid_seq'::regclass);
 :   ALTER TABLE public.room ALTER COLUMN roomid DROP DEFAULT;
       public          root    false    222    221    222            �           2604    49811    username userid    DEFAULT     r   ALTER TABLE ONLY public.username ALTER COLUMN userid SET DEFAULT nextval('public.username_userid_seq'::regclass);
 >   ALTER TABLE public.username ALTER COLUMN userid DROP DEFAULT;
       public          root    false    216    215    216            g          0    49879    admin 
   TABLE DATA                 public          root    false    227   �h       f          0    49863    booking 
   TABLE DATA                 public          root    false    226   i       ^          0    49819    hotel 
   TABLE DATA                 public          root    false    218   �i       i          0    49893    loggedin 
   TABLE DATA                 public          root    false    229   Yk       d          0    49851    review 
   TABLE DATA                 public          root    false    224   �k       b          0    49836    room 
   TABLE DATA                 public          root    false    222   �l       _          0    49827    roomtype 
   TABLE DATA                 public          root    false    219   �m       \          0    49808    username 
   TABLE DATA                 public          root    false    216   Kn       w           0    0    booking_bookingid_seq    SEQUENCE SET     C   SELECT pg_catalog.setval('public.booking_bookingid_seq', 6, true);
          public          root    false    225            x           0    0    hotel_hotelid_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public.hotel_hotelid_seq', 5, true);
          public          root    false    217            y           0    0    loggedin_logid_seq    SEQUENCE SET     @   SELECT pg_catalog.setval('public.loggedin_logid_seq', 2, true);
          public          root    false    228            z           0    0    review_reviewid_seq    SEQUENCE SET     A   SELECT pg_catalog.setval('public.review_reviewid_seq', 5, true);
          public          root    false    223            {           0    0    room_hotelid_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public.room_hotelid_seq', 1, false);
          public          root    false    220            |           0    0    room_roomid_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.room_roomid_seq', 9, true);
          public          root    false    221            }           0    0    username_userid_seq    SEQUENCE SET     A   SELECT pg_catalog.setval('public.username_userid_seq', 6, true);
          public          root    false    215            �           2606    49868    booking booking_pkey 
   CONSTRAINT     Y   ALTER TABLE ONLY public.booking
    ADD CONSTRAINT booking_pkey PRIMARY KEY (bookingid);
 >   ALTER TABLE ONLY public.booking DROP CONSTRAINT booking_pkey;
       public            root    false    226            �           2606    49826    hotel hotel_pkey 
   CONSTRAINT     S   ALTER TABLE ONLY public.hotel
    ADD CONSTRAINT hotel_pkey PRIMARY KEY (hotelid);
 :   ALTER TABLE ONLY public.hotel DROP CONSTRAINT hotel_pkey;
       public            root    false    218            �           2606    49898    loggedin loggedin_pkey 
   CONSTRAINT     W   ALTER TABLE ONLY public.loggedin
    ADD CONSTRAINT loggedin_pkey PRIMARY KEY (logid);
 @   ALTER TABLE ONLY public.loggedin DROP CONSTRAINT loggedin_pkey;
       public            root    false    229            �           2606    49844    room room_pkey 
   CONSTRAINT     Y   ALTER TABLE ONLY public.room
    ADD CONSTRAINT room_pkey PRIMARY KEY (hotelid, roomid);
 8   ALTER TABLE ONLY public.room DROP CONSTRAINT room_pkey;
       public            root    false    222    222            �           2606    49833    roomtype roomtype_pkey 
   CONSTRAINT     Z   ALTER TABLE ONLY public.roomtype
    ADD CONSTRAINT roomtype_pkey PRIMARY KEY (typename);
 @   ALTER TABLE ONLY public.roomtype DROP CONSTRAINT roomtype_pkey;
       public            root    false    219            �           2606    49817    username username_email_key 
   CONSTRAINT     W   ALTER TABLE ONLY public.username
    ADD CONSTRAINT username_email_key UNIQUE (email);
 E   ALTER TABLE ONLY public.username DROP CONSTRAINT username_email_key;
       public            root    false    216            �           2606    49815    username username_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.username
    ADD CONSTRAINT username_pkey PRIMARY KEY (userid);
 @   ALTER TABLE ONLY public.username DROP CONSTRAINT username_pkey;
       public            root    false    216            �           2606    49887    admin admin_hotelid_fkey    FK CONSTRAINT     |   ALTER TABLE ONLY public.admin
    ADD CONSTRAINT admin_hotelid_fkey FOREIGN KEY (hotelid) REFERENCES public.hotel(hotelid);
 B   ALTER TABLE ONLY public.admin DROP CONSTRAINT admin_hotelid_fkey;
       public          root    false    3260    227    218            �           2606    49882    admin admin_userid_fkey    FK CONSTRAINT     |   ALTER TABLE ONLY public.admin
    ADD CONSTRAINT admin_userid_fkey FOREIGN KEY (userid) REFERENCES public.username(userid);
 A   ALTER TABLE ONLY public.admin DROP CONSTRAINT admin_userid_fkey;
       public          root    false    227    216    3258            �           2606    49874 #   booking booking_roomid_hotelid_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.booking
    ADD CONSTRAINT booking_roomid_hotelid_fkey FOREIGN KEY (roomid, hotelid) REFERENCES public.room(roomid, hotelid);
 M   ALTER TABLE ONLY public.booking DROP CONSTRAINT booking_roomid_hotelid_fkey;
       public          root    false    226    222    222    226    3264            �           2606    49869    booking booking_userid_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.booking
    ADD CONSTRAINT booking_userid_fkey FOREIGN KEY (userid) REFERENCES public.username(userid);
 E   ALTER TABLE ONLY public.booking DROP CONSTRAINT booking_userid_fkey;
       public          root    false    3258    226    216            �           2606    49899    loggedin loggedin_userid_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.loggedin
    ADD CONSTRAINT loggedin_userid_fkey FOREIGN KEY (userid) REFERENCES public.username(userid);
 G   ALTER TABLE ONLY public.loggedin DROP CONSTRAINT loggedin_userid_fkey;
       public          root    false    229    3258    216            �           2606    49857    review review_hotelid_fkey    FK CONSTRAINT     ~   ALTER TABLE ONLY public.review
    ADD CONSTRAINT review_hotelid_fkey FOREIGN KEY (hotelid) REFERENCES public.hotel(hotelid);
 D   ALTER TABLE ONLY public.review DROP CONSTRAINT review_hotelid_fkey;
       public          root    false    224    3260    218            �           2606    49845    room room_typename_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.room
    ADD CONSTRAINT room_typename_fkey FOREIGN KEY (typename) REFERENCES public.roomtype(typename);
 A   ALTER TABLE ONLY public.room DROP CONSTRAINT room_typename_fkey;
       public          root    false    219    222    3262            g   ;   x���v
Q���W((M��L�KL���Ss�	uV�0�Q0Դ��$��HG���� �F�      f   �   x��н
�0�Oq[�r�����C��T����ź��^��d�����%M�է��?��=<�k>L�}|��?��6*^)��I�Z�d�$�'%� K�����p�v�4����#���q�r�:�|�
��{�)V��TN�����9�A8�1�;K���d�#t�� E%�rb.I>8^�      ^   m  x���Qk�0���ys�!km��^�`�)X�{�w���������T�@in���GN�I>��Y6�O��.KYt6�@����0g�k����NlD�6�A�a��A�T_��t��S�S���!�b�� ����~4Hs:Ȳ*ބZo���3��ǗV�]H.���2��(��8.d��R�*⮕�4�r��Ւf�k���8I{�wQu�����ԺrG$I��i��v��I<��Ql�L���Q#0M�u�p���Q7(m��`�z�v�&����,*I��x��o��d����,����
7Mb���O�@�Xn���<��a��1��p���</eF>تDو��˷��KO1&�V�h�      i   �   x���v
Q���W((M��L���OOOM��Ss�	uV�0�Q "����<���T�Ԋ�܂�T���\u�8P}f�ad`d�k`�k`�``nD�z��Ɔ����\�D�dDЦ��,VYX��Y-� Y�� I�;3      d   �   x���MK�@��}~�q�!�&��J��T0����D&3e:���{#�6�{������n���t��V���x�y|�v8_�����#�c�<+�jc���.�����g�q�2���zJ@�q<���.֋�Z�[ʔ�0y(����*U�EJ�J��@�q
Y��a�S��E��w9���V����-�22��8�ՕV�X?glq9      b   �   x����
�0F�<�ݢ ����T0B@*�Ꞷ��������� �@���d^�k	2//���5������&
�,g�/��XUY��Q8�hT����ߐ$@����\!$�8j�G*b��I�ƾ(TؠHl!F]{g�"t٢��"d Q}J1��	�@�2,co=ү�      _   �   x���K�@ཿ��,�0{lZE��@���x�:�̄��� w.��|����D���*��ėuY������03C�D��Դ����b^���+۞�o�H��l�.����)g:u�\5��Yw�HX���N�ά��՝����o(���t�m�+I����>�"�Gt�1<7�/��u�      \     x���AO� �{?�jb�Phiv��jt&vzg-I��4�9��>�v��R���
�<B����5*W�4�6���Ω��F������BW�ŏ��c�V���7V-շ4C�pm����ގ��o�0�f"���Q9âޒ}@*�?۠A�����V.������V��u�J����S�C��S���M��9g�%��vFw?�&��(��fJ��dB(���x z}��~��0Y"��j���<υ��Vz�@$���������_��,     