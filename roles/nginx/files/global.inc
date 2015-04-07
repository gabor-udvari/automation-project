# Taken from http://codex.wordpress.org/Nginx
# Global restrictions configuration file.
# Designed to be included in any server {} block.
location = /favicon.ico {
	log_not_found off;
	access_log off;
}

location = /robots.txt {
	allow all;
	log_not_found off;
	access_log off;
}

# Deny all attempts to access hidden files such as .htaccess, .htpasswd, .DS_Store (Mac).
# Keep logging the requests to parse later (or to pass to firewall utilities such as fail2ban)
location ~ /\. {
	deny all;
}

# Deny access to any files with a .php extension in the uploads directory
# Works in sub-directory installs and also in multisite network
# Keep logging the requests to parse later (or to pass to firewall utilities such as fail2ban)
location ~* /(?:uploads|files|assets)/.*\.php$ {
	deny all;
}

# Add additional rule for the cached resources
location ~ \.(gif|jpg|png|js|css)$ {
	expires 30d;
	# try_files $uri /public/$uri;
}

# pass the PHP scripts to FastCGI server
#
location ~ \.php$ {
	fastcgi_split_path_info ^(.+\.php)(/.+)$;
	if (!-f $document_root$fastcgi_script_name) {
		return 404;
	}
	# fastcgi_pass 127.0.0.1:9000;
	fastcgi_pass unix:/var/run/php5-fpm.sock;
	fastcgi_index index.php;
	include fastcgi_params;
}
